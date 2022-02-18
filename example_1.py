import numpy as np
import rirgenerator as RG
import matplotlib.pyplot as plt
import scipy.io as sio

c = 340					# Sound velocity (m/s)
fs = 16000				# Sample frequency (samples/s)
r = [2.5, 2, 1.5]			# Receiver position [x y z] (m)
s = [2.5, 1.5, 1.5]			# Source position [x y z] (m)
L = [6, 4, 3]				# Room dimensions [x y z] (m)
beta = 0.2				# Reverberation time (s)
n = 4096				# Number of samples

info = sio.loadmat('infor.mat') 
direct = info['direct_1'] # 平面夹角 仰俯角 [[30, 45], [45, 45]]
rir_1 = info['rir_1'] # [[rir1], [rir2]]

h = RG.rir_generator(c, fs, r, s, L, beta=beta,  nsample=n, rir_direct=rir_1, ang_direct=direct)
sio.savemat('python.mat', {'h_python':h[0, :]})
plt.plot(h[0,:])
plt.show()