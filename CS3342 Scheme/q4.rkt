#lang scheme

;Eric Robinson
;Assignment 3
;CS3342
;erobin25
;250598791

(define insert (lambda (x y) 
  (if (equal? '() y)
       y
       (cons (car y) (cons x (insert x (cdr y))))
  )
                 )
  )

(insert 'f '(b c a d))
(insert (+ 1 3) '(b a f d))
(insert '() '(b a c f d a))