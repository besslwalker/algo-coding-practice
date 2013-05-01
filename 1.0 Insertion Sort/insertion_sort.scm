;;; Insertion Sort (Integers)
;;; Bess L. Walker
;;; 11-14-11
;;; Scheme is a whole different way of thinking here.

;; Given a number and a sorted list, inserts the number into its sorted position
(define insert
		(lambda (x sorted-list)
				(if (null? sorted-list)
					(list x)
					(if (< x (car sorted-list)) 
					    (cons x sorted-list) 
					    (cons (car sorted-list) (insert x (cdr sorted-list)))))))
		
;; A tail-recursive insert
;; I'm not sure I like this append business, it doesn't feel right for
;; the thinking-type I'm trying to use here.
(define insert-tr
	(lambda (x sorted-list)
		(if (null? sorted-list)
			(list x)
			(letrec ((iter
						(lambda (checked unchecked)
							(cond ((null? unchecked) (append checked (list x)))
								  ((< x (car unchecked)) (append checked (list x) unchecked))
								  (else 
								   	(iter (append checked (list (car unchecked)))
								   		  (cdr unchecked)))))))
					(iter '() sorted-list)))))
					
;; With my current level of thinking in this paradigm, I can't
;; think of a way to get rid of those appends.  I don't know 
;; that it is impossible, but it does seem unlikely that
;; there is a direct non-recursive way to add to the end of a 
;; recursively-defined list.  You have to go to the end to get 
;; to the end (without any special end pointers, etc.).

;; Given a list, returns the sorted permutation of that list
(define insertion-sort
		(lambda (unsorted-list)
				(if (or (not (list? unsorted-list))
					    (= (length unsorted-list) 0)
					    (= (length unsorted-list) 1))
					unsorted-list
					(insert-tr (car unsorted-list) (insertion-sort (cdr unsorted-list))))))
					
;; Example output
(let 
	((permut-1 '(0 1 2 3 4 5))
	 (permut-2 '(5 4 3 2 1 0))
	 (permut-3 '(2 11 14 9 5 9)))
	(begin
		(display permut-1)
		(newline)
		(display (insertion-sort permut-1))
		
		(newline)
		(newline)
		
		(display permut-2)
		(newline)
		(display (insertion-sort permut-2))
		
		(newline)
		(newline)
		
		(display permut-3)
		(newline)
		(display (insertion-sort permut-3))
		
		(newline)))
	  
	 
	 
					