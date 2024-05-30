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
    plt.title(f'{filename} - 53 coefficients, Blackman')
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
    file_path = '../sigD.csv'  # Adjust the path as necessary
    # Define the filter coefficients
    coefficients = [
0.000000000000000000,
0.000040262106974371,
0.000170024258399472,
0.000406690199474799,
0.000772918706884466,
0.001296076521368535,
0.002007023183673962,
0.002938268639323423,
0.004121602274626644,
0.005585344389067255,
0.007351413495736279,
0.009432431456742390,
0.011829100502165908,
0.014528080108850198,
0.017500567401953101,
0.020701743512651884,
0.024071192879055254,
0.027534336698251928,
0.031004850406466316,
0.034387963495681552,
0.037584473605140306,
0.040495250787391433,
0.043025966563228178,
0.045091759205407367,
0.046621543646666895,
0.047561692004237828,
0.047878847901159989,
0.047561692004237828,
0.046621543646666902,
0.045091759205407367,
0.043025966563228192,
0.040495250787391440,
0.037584473605140313,
0.034387963495681552,
0.031004850406466326,
0.027534336698251945,
0.024071192879055264,
0.020701743512651888,
0.017500567401953118,
0.014528080108850200,
0.011829100502165906,
0.009432431456742402,
0.007351413495736279,
0.005585344389067264,
0.004121602274626658,
0.002938268639323424,
0.002007023183673965,
0.001296076521368534,
0.000772918706884464,
0.000406690199474800,
0.000170024258399472,
0.000040262106974370,
0.000000000000000000
    ]
    t, y = load_data_from_csv(file_path)
    if t is not None and y is not None:
        Fs = 1.0 / (t[1] - t[0])  # Estimate the sampling frequency
        filtered_signal = apply_fir_filter(y, coefficients)
        plot_signals_and_fft(t, y, filtered_signal, Fs, file_path.split('/')[-1])

if __name__ == '__main__':
    main()

# %%
