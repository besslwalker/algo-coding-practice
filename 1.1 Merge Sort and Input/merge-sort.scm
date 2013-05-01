;;; Merge Sort (Integers) and Input
;;; Bess L. Walker
;;; 12-6-11
;;; Merge sort should be easy with Scheme; it loves lists and recursion
;;; On the other hand I don't really know anything about input in Scheme
;;; And splitting Scheme lists is actually a big pain.
;;; So much for that.

;; Given a list, return a cons pair with the first and second halves of the list
;;
;; Explaining pop-push:
;; 	counter-list just has to have the same number of elements as original list
;;    luckily, original-list has its own number of elements, so we just use it
;;  pop-list will be the second half of the list; it starts as the original list
;;  push-list will be the reverse of the first half of the list; it starts empty
;;  At each recursion, 
;;    if there aren't two elements in counter-list,
;;      return the reverse of push-list and the pop-list
;;    otherwise, remove two elements from counter-list
;;      pop the (car pop-list) from the pop-list and push it on the push-list
;;  Since two elements are removed from counter-list for each pop-push,
;;  	we move only half the list to push-list, thus splitting the original list
;;
;; Oh, hey, it's tail-recursive, that's neat.
(define split-list
	(lambda (original-list)
			(letrec ((pop-push (lambda (counter-list pop-list push-list)
									   (if (or (null? counter-list) (null? (cdr counter-list)))
									  	   (cons (reverse push-list) pop-list)
									  	   (pop-push (cddr counter-list)
									  	             (cdr pop-list)
									  	             (cons (car pop-list) push-list))))))
					 (pop-push original-list original-list '()))))

;; Given two sorted lists, merges them into one.
;; So that I can use mostly cons in the recursive body, I actually
;; construct the accumulator list in reverse sorted order.
;; Then, before merge spits it out, it reverses the final list.
(define merge
	(lambda (left right)
			(reverse 
			 (letrec ((inner-merge (lambda (acc-list left-list right-list)
										   (cond ((and (null? left-list) (null? right-list)) acc-list)
										  	 	 ((null? left-list) (append (reverse right-list) acc-list))
										  	 	 ((null? right-list) (append (reverse left-list) acc-list))
										  		 ((<= (car left-list) (car right-list)) 
										  		  (inner-merge (cons (car left-list) acc-list) (cdr left-list) right-list))
										  		 (else 
										  		  (inner-merge (cons (car right-list) acc-list) left-list (cdr right-list)))))))
				  (inner-merge '() left right)))))
					 			
;; Given a list of integers, returns a new list with those integers in sorted order.
(define merge-sort
	(lambda (unsorted-list)
			(if (or (null? unsorted-list) (null? (cdr unsorted-list)))
				unsorted-list
				(merge (merge-sort (car (split-list unsorted-list)))
				       (merge-sort (cdr (split-list unsorted-list)))))))
				       
(let ((permut-1 '(0 1 2))
	  (permut-2 '(5 4 3 2 1 0))
	  (permut-3 '(3 12 6 11 5 1)))
	(begin
	 (display permut-1)
	 (newline)
	 (display (merge-sort permut-1))
	 
	 (newline)
	 (newline)
	 
	 (display permut-2)
	 (newline)
	 (display (merge-sort permut-2))
	 
	 (newline)
	 (newline)
	 
	 (display permut-3)
	 (newline)
	 (display (merge-sort permut-3))
	 
	 (newline)))
	 
;; Asks the user for a comma-delimited list of integers, filters out
;; any bad input, and "returns" a list with just the good input in it, in
;; the order entered by the user.
;; As a side-effect, also displays the good and bad input lists.
(define prompt
	(begin
		(display "Enter a list of integers separated by commas: ")
		(letrec ((good-bad-input (lambda (input good bad)
									 (cond ((null? input) (cons good bad))
									 	   ((integer? (string->number (car input)))
									     		(good-input (cdr input) 
									     		(cons (car input) good) 
									     		bad))
									 	   (else (good-input (cdr input)
									       			good
									       			(cons (car input) bad)))))))
				(good-bad-input (string-tokenize 
									(char-set-delete char-set:graphic ',') 
									(read)) 
								'() 
								'()))))
				
(display (prompt))