#lang racket
(require math/array)
(require dyoo-while-loop)

(define mtx (array #[#[1 2] #[3 4]]))

(display (array-ref mtx (vector 1 1)))
(display "\n")

(define i 0)
(while #t
       (display i)
       (set! i (+ i 1))
       (if (> i 5) (break) #\e)
)
