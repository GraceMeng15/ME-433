# %%
import csv
import numpy as np
import matplotlib.pyplot as plt

# Function to load data from CSV
def load_data_from_csv(filepath):
    t = []
    data1 = []

    with open(filepath, 'r') as file:
        reader = csv.reader(file)
        for row in reader:
            t.append(float(row[0]))
            data1.append(float(row[1]))

    return np.array(t), np.array(data1)

# Function to compute FFT of the signal
def compute_fft(t, y):
    Fs = 1.0 / (t[1] - t[0])  # Calculate the sampling frequency
    n = len(y)                # Length of the signal
    k = np.arange(n)
    T = n / Fs
    frq = k / T               # Two sides frequency range
    frq = frq[range(int(n / 2))]  # One side frequency range
    Y = np.fft.fft(y) / n     # FFT computing and normalization
    Y = Y[range(int(n / 2))]

    return frq, Y

# Function to plot the signal and its FFT
def plot_signal_and_fft(t, y, frq, Y):
    fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(10, 8))

    # Plot time domain
    ax1.plot(t, y, 'b', linewidth=0.5)
    ax1.set_title('Signal vs Time')
    ax1.set_xlabel('Time [s]')
    ax1.set_ylabel('Amplitude')

    # Plot frequency domain
    ax2.loglog(frq, abs(Y), 'b' , linewidth=0.5)  # Plotting the FFT
    ax2.set_title('Fourier Transform')
    ax2.set_xlabel('Freq (Hz)')
    ax2.set_ylabel('|Y(freq)|')

    plt.tight_layout()
    plt.show()

# Main execution flow
if __name__ == '__main__':
    file_paths = ['../sigA.csv', '../sigB.csv', '../sigC.csv', '../sigD.csv']  # List of CSV files

    for file_path in file_paths:
        t, y = load_data_from_csv(file_path)
        frq, Y = compute_fft(t, y)
        plot_signal_and_fft(t, y, frq, Y)
        

# %%
