# %%
import csv
import numpy as np
import matplotlib.pyplot as plt

def load_data_from_csv(filepath):
    t = []
    data1 = []
    try:
        with open(filepath, 'r') as file:
            reader = csv.reader(file)
            for row in reader:
                if len(row) < 2:
                    continue  # Skip rows with insufficient data
                t.append(float(row[0]))
                data1.append(float(row[1]))
    except Exception as e:
        print(f"Failed to read {filepath}: {e}")
        return None, None
    return np.array(t), np.array(data1)

def iir_low_pass_filter(signal, A, B):
    new_average = np.zeros(len(signal))
    new_average[0] = signal[0]  # Initialize the first element
    for i in range(1, len(signal)):
        new_average[i] = A * new_average[i-1] + B * signal[i]
    return new_average

def compute_fft(t, y, Fs):
    n = len(y)
    k = np.arange(n)
    T = n / Fs
    frq = k / T
    frq = frq[range(int(n / 2))]
    Y = np.fft.fft(y) / n
    Y = Y[range(int(n / 2))]
    return frq, Y

def plot_fft_comparison(t, y, y_filtered, Fs, A, B, filename):
    frq, Y = compute_fft(t, y, Fs)
    frq_filtered, Y_filtered = compute_fft(t[:len(y_filtered)], y_filtered, Fs)
    
    plt.figure(figsize=(12, 6))
    plt.loglog(frq, abs(Y), 'k', label='Original', linewidth=0.5)
    plt.loglog(frq_filtered, abs(Y_filtered), 'r', label='Filtered', linewidth=0.5)
    plt.title(f'FFT Comparison for {filename} - Filter Coefficients A={A}, B={B}')
    plt.xlabel('Frequency (Hz)')
    plt.ylabel('|Y(freq)|')
    plt.legend()
    plt.show()

def run_csv(sig, A, B):
    t, y = load_data_from_csv(sig)
    if t is None or y is None:
        print(f"Skipping {sig} due to loading issues.")
        return
    Fs = 1.0 / (t[1] - t[0])
    
    y_filtered = iir_low_pass_filter(y, A, B)
    plot_fft_comparison(t, y, y_filtered, Fs, A, B, sig)

if __name__ == '__main__':
    sig_files = ["../sigA.csv", "../sigB.csv", "../sigC.csv", "../sigD.csv"]
    filter_coefficients = [(0.9, 0.1), (0.8, 0.2)]
    
    for sig_file in sig_files:
        for A, B in filter_coefficients:
            run_csv(sig_file, A, B)

# %%
