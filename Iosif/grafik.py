import pandas as pd
import matplotlib.pyplot as plt

data = {
    'N': [1000, 5000, 100000, 500000, 1000000],
    'Ответ': [977, 1809, 3617, 34465, 68929],
    'Время расчета (сек)': [0.001, 0.019, 0.088, 2.005, 7.104]
}
df = pd.DataFrame(data)
plt.figure(figsize=(10, 6))
plt.plot(df['N'], df['Время расчета (сек)'], 'b-o', linewidth=2, markersize=8)
plt.xscale('log')
plt.xticks(df['N'], ['1 000', '5 000', '100 000', '500 000', '1 000 000'], 
           rotation=45, ha='right')
plt.ylabel('Время расчета (сек)', fontsize=12)
plt.title('Зависимость времени расчета от размера массива', fontsize=14)
plt.grid(True, alpha=0.3)
plt.tight_layout()
plt.savefig('graph.png', dpi=300, bbox_inches='tight') 
plt.show()
