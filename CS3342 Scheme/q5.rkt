#lang scheme

;Eric Robinson
;Assignment 3
;CS3342
;erobin25
;250598791


(define ericmin (lambda (x) 
  (if (= 1 (length x)) (car x)           
      (if (= 2 (length x)) 
          (if (< (car x) (car (cdr x)))  
               (car x)                   
               (car (cdr x))             
          )
          (ericmin (cdr x))                
      )     
  )
                )
  )
 
(ericmin '(4. 3. 2. 5.))
(ericmin '(4 3 0.4 5))
(ericmin '(4 -3.5 0.4 -5))
(ericmin '(1))