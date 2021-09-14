#lang racket
;--------------------------------------------------------------------------------------
;Exe1
#|Da el elemento de la secuencia de Fibonacci de manera recursiva mediante la fórmula:
fib(n) = fib(n-1) + fib(n-2)|#

(define (fib n)
  (if (<= n 2)
      1
      (+ (fib (- n 1)) (fib (- n 2)))))

(fib 7)

#|La función 'fib1' recibe un número para así llamar a la función auxilar 'fibAux' y
 regresar el elemento de la serie de Fibonacci,con el fin de que se realize
 mediante recursión terminal|#
(define (fib1 n)
  (fibAux n 0 1))

(define (fibAux n a b)
  (if (= n 0 )
      a
      (if (= n 1)
          b
          (fibAux (- n 1) b (+ a b)))))

(fib1 7)
;-----------------------------------------------------------------------------------------
;Exe2
#|La función 'gcdF' recibe dos valores para poder identificar el máximo común divisor|#
(define (gcdFunct n m)
   (if (= m 0) n
    (gcdFunct m (modulo n m))))

(gcdFunct 6 8)
;-----------------------------------------------------------------------------------------
;Exe3

#|La función "sum" recibe un número cualquiera y suma todos los anteriores a éste de forma
 recursiva|#
(define (sum n)
  (if (= n 1)
      1
      (+ n (sum (- n 1)))))

(sum 4)

#|La función 'sum1' recibe un número y llama a la función auxiliar 'sumAux', la cual se
  encargará de hacer la sumatoria de todos los números anteriores al dado|#

(define (sum1 n)
  (sumAux n 0))

(define (sumAux n a)
  (if (= n 0)
      a
      (sumAux (- n 1) (+ a n))))

(sum1 4)


