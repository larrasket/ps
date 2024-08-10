(ns plus-minus)
  
(defn plusMinus [arr]
  (if (empty? arr)
    (println 0)
    (let [l (count arr)
          p (count (filter pos? arr))
          z (count (filter zero? arr))
          n (- l (+ p z))]
      (println (with-precision 6 (float (/ p l))))
      (println (with-precision 6 (float (/ n l))))
      (println (with-precision 6 (float (/ z l)))))))

(plusMinus [1 1 0 -1 -1])

