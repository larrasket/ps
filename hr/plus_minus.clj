(ns hr)
  
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

;; https://www.hackerrank.com/challenges/three-month-preparation-kit-mini-max-sum
(defn miniMaxSum [arr]
  (let [sarr (sort arr)
        minsum (reduce + (take 4 sarr))
        maxsum (reduce + (drop 1 sarr))]
    (print (format "%d %d" minsum maxsum))))
    




