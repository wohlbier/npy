#!/usr/bin/env python

import numpy as np

if __name__ == "__main__":
    N = 10
    y = np.random.rand(N)
    np.save('./test.npy', y, allow_pickle = False)
