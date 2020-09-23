#!/usr/bin/env python

import numpy as np

if __name__ == "__main__":
    N = 1000
    y = np.random.rand(N).astype(np.float32)
    print(y)
    np.save('./test.npy', y, allow_pickle = False)
