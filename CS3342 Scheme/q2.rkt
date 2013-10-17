#lang scheme

;Eric Robinson
;Assignment 3
;CS3342
;erobin25
;250598791

(define mycddadr(lambda(p) (cdr(cdr(car(cdr p))))))

(mycddadr '(1 (2 (3 4)5)6))
(mycddadr '(a (b (c))))

