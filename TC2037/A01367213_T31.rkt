#lang racket

;-------------Exe 1---------------------
(define(positives lst)
  (filter positive? lst)
  )

(positives '(-3 -2 5 8 1 -4))

;-----------Exe 2-----------------------
(define(add-list lst)
  (apply + lst))


(add-list '(-4 -3))


;-------------Exe 3---------------------
(define (average lst)
  (if(null? lst)0
     (/ (apply + lst) (length lst))
     )
  )

(average '(85 90 89 86))

;-------------Exe 4---------------------
(define(insert n lst)
  (sort (cons n lst) <)
  )

(insert 3 '(1 4 2 7))