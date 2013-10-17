#lang scheme

;Eric Robinson
;Assignment 3
;CS3342
;erobin25
;250598791

(define dbl (lambda (x y) 
  (if (equal? '() y)
       y
       (if (equal? x (car y))
           (cons x (cons x (dbl x (cdr y))))
           (cons (car y) (dbl x (cdr y)))
       )
  )
              )
  )
 
(dbl 'a '(b c a d))
(dbl (- 4 2) '(1 2 3 4 2))
(dbl '+ '(1 + + 2 + + 3))