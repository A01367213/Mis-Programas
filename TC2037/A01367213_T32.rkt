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
(define (insert n lst)
  (insertAux n lst '() 0)
  )

(define (insertAux n lst1 lst2 cnt)
  (if (null? lst1)
      (if (= cnt 0)
          (append lst2 (list n))
          lst2)
      (if (= cnt 1)
          (insertAux n (cdr lst1) (append lst2 (list (car lst1))) 1)
          (if (< n (car lst1))
              (insertAux n lst1 (append lst2 (list n)) 1)
              (insertAux n (cdr lst1) (append lst2 (list (car lst1))) 0))
          )
      )
  )

(insert 7 '(5 6 8 9))

;-------------Exe 5---------------------




;-------------Exe 6---------------------
(define (compress lst)
  (compressAux lst '() 0)
  )

(define (compressAux lst1 lst2 n)
  (if (null? lst1)
      lst2
      (if (equal? (car lst1) n)
          (compressAux (cdr lst1) lst2 (car lst1))
          (compressAux (cdr lst1) (append lst2 (list (car lst1))) (car lst1))
          )
      )
  )

(compress '( g g t g h h h))

;-------------Exe 7---------------------
(define (encode lst)
  (encodeAux lst '() '() (car lst) 0 0)
  )

(define (encodeAux lst1 lst2 lst3 e cnt1 cnt2)
  (if (null? lst1)
      (append lst2 (cons (list cnt1 e) lst3))
      (if (equal? (car lst1) e)
          (encodeAux (cdr lst1) lst2 lst3 (car lst1) (+ cnt1 1) 1)
          (if (= cnt2 0)
              (encodeAux (cdr lst1) lst2 lst3 (car lst1) 1 1)
              (encodeAux (cdr lst1) (append lst2 (cons (list cnt1 e) lst3)) '() (car lst1) 1 1)
              )
          )
      )
  )

(encode '(a a b b b b b c c d d))

;-------------Exe 8---------------------
(define (replic n lst)
  (replica n lst '() 0)
   )

(define (replica n lst1 lst2 cnt)
  (if (null? lst1)
      lst2
      (if (= n cnt)
      (replica n (cdr lst1) lst2 0)
      (replica n lst1 (append lst2 (list (car lst1))) (+ cnt 1)))
      )
  )

(replic 3 '(a b c))

;-------------Exe 9---------------------
(define (linear-search lst n eq-fun)
  (linearAux lst n eq-fun 0)
   )

(define (linearAux lst n eq-fun cnt)
  (if (eq-fun n (car lst))
      cnt
      (linearAux (cdr lst) n eq-fun (+ cnt 1))
      )
  )

(linear-search '(a b c d e f) 'd equal?)