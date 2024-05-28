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

def moving_average_filter(data, window_size):
    filtered_data = np.convolve(data, np.ones(window_size) / window_size, 'valid')
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

def plot_fft_comparison(t, y, y_filtered, Fs, window_size, filename):
    frq, Y = compute_fft(t, y, Fs)
    frq_filtered, Y_filtered = compute_fft(t[:len(y_filtered)], y_filtered, Fs)
    
    plt.figure(figsize=(12, 6))
    plt.loglog(frq, abs(Y), 'k', label='Original', linewidth=0.5)
    plt.loglog(frq_filtered, abs(Y_filtered), 'r-.', label='Filtered', linewidth=0.5)
    plt.title(f'FFT for {filename} - Moving Average Window Size x = {window_size}')
    plt.xlabel('Frequency (Hz)')
    plt.ylabel('|Y(freq)|')
    plt.legend()
    plt.show()

def run_csv(sig, window_size):
    t, y = load_data_from_csv(sig)
    if t is None or y is None:
        print(f"Skipping {sig} due to loading issues.")
        return
    Fs = 1.0 / (t[1] - t[0])
    y_filtered = moving_average_filter(y, window_size)
    plot_fft_comparison(t, y, y_filtered, Fs, window_size, sig)

if __name__ == '__main__':
    sig_files = ["../sigA.csv", "../sigB.csv", "../sigC.csv", "../sigD.csv"]
    window_size = 3  # Example window size
    
    for sig_file in sig_files:
        run_csv(sig_file, window_size)

# %%
