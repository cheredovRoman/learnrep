(defun delete-next (lst elem)
  (cond
    ((null lst) lst)
    ((equal (car lst) elem) (cddr lst))
    (t (cons (car lst) (delete-next (cdr lst) elem)))))
(setq lst '(1 2 3 4 5))
(setq elem 3)
(print (delete-next lst elem))