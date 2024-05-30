# %%
import numpy as np
import matplotlib.pyplot as plt
import csv

def load_data_from_csv(filepath):
    t = []
    data = []
    with open(filepath, 'r') as file:
        reader = csv.reader(file)
        for row in reader:
            t.append(float(row[0]))
            data.append(float(row[1]))

    return np.array(t), np.array(data)

def apply_fir_filter(data, coefficients):
    filtered_data = np.convolve(data, coefficients, mode='same')
    return filtered_data

def compute_fft(t, y, Fs):
    n = len(y)
    k = np.arange(n)
    T = n / Fs
    frq = k / T
    frq = frq[range(int(n / 2))]
    Y = np.fft.fft(y) / n
    Y = Y[range(int(n / 2))]
    return frq, Y

def plot_signals_and_fft(t, original, filtered, Fs, filename):
    # Plot time domain and frequency domain representations.
    frq, Y_original = compute_fft(t, original, Fs)
    frq, Y_filtered = compute_fft(t, filtered, Fs)

    plt.figure(figsize=(12, 10))
    plt.subplot(2, 1, 1)
    plt.plot(t, original, label='Unfiltered', color='black', alpha=0.9)
    plt.plot(t, filtered, label='Filtered', color='red')
    plt.title(f'{filename} - 19 coefficients, Rectangular')
    plt.xlabel('Time [s]')
    plt.ylabel('Amplitude')
    plt.legend()

    plt.subplot(2, 1, 2)
    plt.loglog(frq, np.abs(Y_original), label='Unfiltered FFT', color='black')
    plt.loglog(frq, np.abs(Y_filtered), label='Filtered FFT', linestyle='--', color='red')
    plt.title('FFT Comparison')
    plt.xlabel('Frequency (Hz)')
    plt.ylabel('Magnitude')
    plt.legend()

    plt.tight_layout()
    plt.show()

def main():
    # Specify the path to the signal file
    file_path = '../sigC.csv'  # Adjust the path as necessary
    # Define the filter coefficients
    coefficients = [
0.050864468366675471,
0.051447898537001137,
0.051965975783172462,
0.052417478485077405,
0.052801340859369245,
0.053116655958639653,
0.053362678224921099,
0.053538825589686409,
0.053644681113902914,
0.053679994163108466,
0.053644681113902914,
0.053538825589686409,
0.053362678224921099,
0.053116655958639653,
0.052801340859369245,
0.052417478485077405,
0.051965975783172462,
0.051447898537001137,
0.050864468366675471
    ]
    t, y = load_data_from_csv(file_path)
    if t is not None and y is not None:
        Fs = 1.0 / (t[1] - t[0])  # Estimate the sampling frequency
        filtered_signal = apply_fir_filter(y, coefficients)
        plot_signals_and_fft(t, y, filtered_signal, Fs, file_path.split('/')[-1])

if __name__ == '__main__':
    main()

# %%
