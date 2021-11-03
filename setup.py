from distutils.core import setup
from distutils.extension import Extension
from Cython.Distutils import build_ext
import numpy as np

sourcefiles = ["rir_generator_core.cpp","rirgenerator.pyx"]
ext_modules = [Extension("rirgenerator", sourcefiles,libraries=['m'])]

setup(
	name = 'RIRGenerator',
	cmdclass = {'build_ext': build_ext},
	ext_modules = ext_modules,
	include_dirs = [np.get_include()]	
)
