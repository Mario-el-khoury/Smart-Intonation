#include <complex>
#include <iostream>
#include <time.h>
#include <math_defines.h>
#include <float.h>

#define DO_FFTW // libfftw
#define DO_SDFT

#if defined(DO_FFTW)
#pragma comment( lib, "d:\\projects\\common\\fftw\\libfftw3-3.lib" )

namespace fftw {
#include <fftw/fftw3.h>
}

fftw::fftw_plan plan_fwd;
fftw::fftw_plan plan_inv;

#endif

typedef std::complex<double> complex;

// Buffer size, make it a power of two if you want to improve fftw
const int N = 750;


// input signal
complex in[N];

// frequencies of input signal after ft
// Size increased by one because the optimized sdft code writes data to freqs[N]
complex freqs[N+1];

// output signal after inverse ft of freqs
complex out1[N];
complex out2[N];

// forward coeffs -2 PI e^iw -- normalized (divided by N)
complex coeffs[N];
// inverse coeffs 2 PI e^iw
complex icoeffs[N];

// global index for input and output signals
int idx;


// these are just there to optimize (get rid of index lookups in sdft)
complex oldest_data, newest_data;

//initilaize e-to-the-i-thetas for theta = 0..2PI in increments of 1/N
void init_coeffs()
{
    for (int i = 0; i < N; ++i) {
        double a = -2.0 * PI * i  / double(N);
        coeffs[i] = complex(cos(a)/* / N */, sin(a) /* / N */);
    }
    for (int i = 0; i < N; ++i) {
        double a = 2.0 * PI * i  / double(N);
        icoeffs[i] = complex(cos(a),sin(a));
    }
}


// initialize all data buffers
void init()
{
    // clear data
    for (int i = 0; i < N; ++i)
        in[i] = 0;
    // seed rand()
    srand(857);
    init_coeffs();
    oldest_data = newest_data = 0.0;
    idx = 0;
}

// simulating adding data to circular buffer
void add_data()
{
    oldest_data = in[idx];
    newest_data = in[idx] = complex(rand() / double(N));

}


// sliding dft
void sdft()
{
    complex delta = newest_data - oldest_data;
    int ci = 0;
    for (int i = 0; i < N; ++i) {
        freqs[i] += delta * coeffs[ci];
        if ((ci += idx) >= N)
            ci -= N;
    }
}

// sliding inverse dft
void isdft()
{
    complex delta = newest_data - oldest_data;
    int ci = 0;
    for (int i = 0; i < N; ++i) {
        freqs[i] += delta * icoeffs[ci];
        if ((ci += idx) >= N)
            ci -= N;
    }
}

// "textbook" slow dft, nested loops, O(N*N)
void ft()
{
    for (int i = 0; i < N; ++i) {
        freqs[i] = 0.0;
        for (int j = 0; j < N; ++j) {
            double a = -2.0 * PI * i * j / double(N);
            freqs[i] += in[j] * complex(cos(a),sin(a));
        }
    }
}

double mag(complex& c)
{
    return sqrt(c.real() * c.real() + c.imag() * c.imag());
}

void powr_spectrum(double *powr)
{
    for (int i = 0; i < N/2; ++i) {
        powr[i] = mag(freqs[i]);
    }

}

int main(int argc, char *argv[])
{
    const int NSAMPS = N*10;
    clock_t start, finish;

#if defined(DO_SDFT)
// ------------------------------ SDFT ---------------------------------------------
    init();

    start = clock();
    for (int i = 0; i < NSAMPS; ++i) {

        add_data();

        sdft();
        // Mess about with freqs[] here
        //isdft();

        if (++idx == N) idx = 0; // bump global index

        if ((i % 1000) == 0)
            std::cerr << i << " iters..." << '\r';
    }
    finish = clock();

    std::cout << "SDFT: " << NSAMPS / ((finish-start) / (double)CLOCKS_PER_SEC) << " fts per second." << std::endl;

    double powr1[N/2];
    powr_spectrum(powr1);
#endif

#if defined(DO_FFTW)

// ------------------------------ FFTW ---------------------------------------------
    plan_fwd = fftw::fftw_plan_dft_1d(N, (fftw::fftw_complex *)in, (fftw::fftw_complex *)freqs, FFTW_FORWARD, FFTW_MEASURE);
    plan_inv = fftw::fftw_plan_dft_1d(N, (fftw::fftw_complex *)freqs, (fftw::fftw_complex *)out2, FFTW_BACKWARD, FFTW_MEASURE);

    init();

    start = clock();
    for (int i = 0; i < NSAMPS; ++i) {

        add_data();

        fftw::fftw_execute(plan_fwd);
        // mess about with freqs here
        //fftw::fftw_execute(plan_inv);

        if (++idx == N) idx = 0; // bump global index

        if ((i % 1000) == 0)
            std::cerr << i << " iters..." << '\r';
    }
    // normalize fftw's output 
    for (int j = 0; j < N; ++j)
        out2[j] /= N;

    finish = clock();

    std::cout << "FFTW: " << NSAMPS / ((finish-start) / (double)CLOCKS_PER_SEC) << " fts per second." << std::endl;
    fftw::fftw_destroy_plan(plan_fwd);
    fftw::fftw_destroy_plan(plan_inv);

    double powr2[N/2];
    powr_spectrum(powr2);
#endif
#if defined(DO_SDFT) && defined(DO_FFTW)
// ------------------------------      ---------------------------------------------
    const double MAX_PERMISSIBLE_DIFF = 1e-11; // DBL_EPSILON;
    double diff;
    // check my ft gives same power spectrum as FFTW
    for (int i = 0; i < N/2; ++i)
        if ( (diff = abs(powr1[i] - powr2[i])) > MAX_PERMISSIBLE_DIFF)
            printf("Values differ by more than %g at index %d.  Diff = %g\n", MAX_PERMISSIBLE_DIFF, i, diff);

#endif
    return 0;
}