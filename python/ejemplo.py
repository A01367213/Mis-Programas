import numpy

#exp = np.exp(-(x**2 + y**2)/(2*sigma**2))

def mexHat(sigma, k):
    M = numpy.zeros((k,k))
    for x in range(0,k):
        for y in range(0,k):
            exp = numpy.exp(-(x**2 + y**2)/(2*sigma**2))
            M[x][y] = 1/(numpy.pi*sigma**2) * (1-(1/2)*((x**2 + y**2)/sigma**2)) * exp
    return M

M = mexHat(1,3)

print(M)
