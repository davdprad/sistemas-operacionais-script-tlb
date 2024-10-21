# import sys
# import matplotlib.pyplot as plt

# plotfile se mostrou antigo, então foi substituido no código
# plt.plotfile(sys.argv[1], cols=(0, 1), names=["Numero de Paginas", "Tempo"], delimiter=" ")
# plt.show()

import numpy as np
import matplotlib.pyplot as plt

# TROCAR O NOME DO ARQUIVO .txt AQUI
# GARANTIR QUE O ARQUIVO .txt ESTEJA NO MESMO DIRETÓRIO
data = np.loadtxt('tlb_resultados.txt', skiprows=1)

numero_paginas = data[:, 0]
tempo_acesso = data[:, 1]

plt.figure(figsize=(10, 6))
plt.plot(numero_paginas, tempo_acesso, marker='o', linestyle='-', color='b', label='Tempo por Acesso')

plt.title("Tempo Médio por Acesso vs. Número de Páginas")
plt.xlabel("Número de Páginas")
plt.ylabel("Tempo Médio por Acesso (microssegundos)")

plt.legend()

plt.grid(True)
plt.show()