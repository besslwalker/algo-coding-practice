;;; Simple input
;;; Bess L. Walker
;;; 12-12-11
;;; Trying to get my head around available functions, etc.

;; Example from http://classes.soe.ucsc.edu/cmps112/Spring03/languages/scheme/SchemeTutorialA.html#io
(define prompt-read
	(lambda (prompt) (display prompt) (read)))
	
;; Example from http://www.scheme.com/tspl3/io.html
(define read-word
	(lambda (p)
		(let f ()
			(let ((c (peek-char p)))
				 (cond ((eof-object? c) '())
				 	   ((char-alphabetic? c) (read-char p)
				 	   						 (cons c (f)))
				 	   (else '()))))))
				 	   
;; Does what I want?
(define read-integer
	(lambda (port)
		(letrec ((read-if-number
					(lambda ()
						(let ((c (peek-char port)))
						 	(cond ((eof-object? c) '())
						 	   	  ((char-numeric? c) (read-char port) (cons c (read-if-number)))
						 	   	  (else '()))))))
			    (read-if-number))))
			    
;; Excellent, that reads an integer.
;; Can I read all the ones I've typed before I hit Return?
