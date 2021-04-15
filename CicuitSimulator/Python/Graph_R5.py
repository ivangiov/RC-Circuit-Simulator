#inport library
import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.image as mpimg 
import numpy as np

#Menampilkan gambar rangkaian (fig1)
img = mpimg.imread('Resources/R5.png')											#Memuat file .png ke variabel img
fig1, ax = plt.subplots(1)														#Membuat figure 1
ax.imshow(img)																	#Memuat gambar img ke figure 1
ax.axis('off')																	#Menghilangkan keterangan sumbu
fig1.canvas.set_window_title('Gambar Rangkaian 5')								#Mengubah window title
fig1.tight_layout()																#Mengatur layout figure


#Menampilkan grafik (fig2)

#Membaca file csv
data = pd.read_csv(r"Output\R5.csv")

#Mendeklarasikan variabel untuk tiap kolom data
time = data['time']
va = data['Va']
vb = data['Vb']
vc = data['Vc']
vd = data['Vd']
i1 = data['I1']
i2 = data['I2']
i3 = data['I3']

#Menggabungkan kolom yang berkaitan
arus = pd.concat([i1,i2,i3], axis = 1)
tegangan = pd.concat([va,vb,vc,vd], axis = 1)

#Membuat figure 2 dengan format 1 kolom x 2 baris
fig2, (ax1,ax2) = plt.subplots(2)

#Visualisasi tegangan node
ax1.set_title('Visualisasi Tegangan Node', size=16)							#Memberi judul subplot
ax1.plot(time, tegangan)													#Memplot grafik
ax1.legend(tegangan, loc='upper right')										#Menampilkan legenda
ax1.set(xlabel='Waktu (s)', ylabel='Tegangan (V)')							#Mengatur nama sumbu
ax1.tick_params('x',labelrotation=35)										#Mengatur rotasi label sumbu x
ax1.tick_params(labelsize=8)												#Mengatur ukuran font label di semua sumbu
ax1.xaxis.set_ticks(np.arange(0, max(time)+(max(time)/15), max(time)/10))	#Mengatur banyaknya label di sumbu x (10)
ax1.grid()																	#Menampilkan grid pada grafik

#Visualisasi arus branch
ax2.set_title('Visualisasi Arus Tiap Branch', size=16)						#Memberi judul subplot
ax2.plot(time, arus)														#Memplot grafik
ax2.legend(arus, loc='upper right')											#Menampilkan legenda
ax2.set(xlabel='Waktu (s)', ylabel='Arus (A)')								#Mengatur nama sumbu
ax2.tick_params('x',labelrotation=35)										#Mengatur rotasi label sumbu x
ax2.tick_params(labelsize=8)												#Mengatur ukuran font label di semua sumbu
ax2.xaxis.set_ticks(np.arange(0, max(time)+(max(time)/15), max(time)/10))	#Mengatur banyaknya label di sumbu x (10)
ax2.grid()																	#Menampilkan grid pada grafik

#Mengatur layout
fig2.tight_layout()

#Mengubah window title
fig2.canvas.set_window_title('Grafik Tegangan dan Arus Rangkaian 5')

#Menyimpan figure 2 dalam bentuk png
plt.savefig('Output\R5.png', bbox_inches='tight', dpi=1000)

#Menampilkan figure 1 dan 2 pada window
plt.show()
