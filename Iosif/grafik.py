import matplotlib.pyplot as plt
import numpy as np

np.set_printoptions(suppress=True, precision=6)

data = np.genfromtxt(r"C:\Users\anaer\OneDrive\Desktop\с++\Iosif\2.csv", 
                     delimiter=",", 
                     encoding='utf-8')
N = data[:, 0]       
times = data[:, 2]   

fig, (ax_l, ax_r) = plt.subplots(1, 2, figsize=(12, 6))

ax_l.plot(N, times, marker="o", linestyle='-', color='blue', linewidth=2, markersize=6)
ax_l.set_xscale("log")
ax_l.set_xlabel("N", fontsize=12)
ax_l.set_ylabel("Time (s)", fontsize=12)
ax_l.set_title("Мой алгоритм", fontsize=14)
ax_l.grid(True, alpha=0.3)

logN = np.log10(N)
logT = np.log10(times)
slope, intercept = np.polyfit(logN, logT, 1)

N_new = np.logspace(np.log10(N.min()), np.log10(5_000_000), 300)
pred_time = 10 ** (intercept + slope * np.log10(N_new))

ax_r.plot(N_new, pred_time, color="red", linewidth=2)
ax_r.scatter(N, times, color="tab:blue", s=25, zorder=5)

mark_N = 5_000_000
mark_time = float(10 ** (intercept + slope * np.log10(mark_N)))
ax_r.scatter([mark_N], [mark_time], color="black", s=50, zorder=6)
ax_r.annotate(f"{mark_time:.1f} seconds on {mark_N:,}",
              xy=(mark_N, mark_time),
              xytext=(0, 15),
              textcoords="offset points",
              ha="center",
              fontsize=9)

ax_r.set_xscale("log")
ax_r.set_xlabel("N", fontsize=12)
ax_r.set_ylabel("Time (s)", fontsize=12)
ax_r.set_title("прогноз", fontsize=14)
ax_r.legend()
ax_r.grid(True, alpha=0.3)

plt.tight_layout()
plt.savefig("graphic.png", dpi=150)
plt.show()
