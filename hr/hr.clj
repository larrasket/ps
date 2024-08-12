(ns hr
  (:require [clojure.string :as str]
            [clojure.edn :as edn]
            [clojure.pprint :as pp]))


(defn plusMinus
  [arr]
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
(defn miniMaxSum
  [arr]
  (let [sarr (sort arr)
        minsum (reduce + (take 4 sarr))
        maxsum (reduce + (drop 1 sarr))]
    (print (format "%d %d" minsum maxsum))))


;; https://www.hackerrank.com/challenges/three-month-preparation-kit-time-conversion
(defn timeConversion
  [s]
  (let [[_ ih m s dn] (re-matches #"(\d+):(\d+):(\d+)(AM|PM)?" s)
        h (cond (and (not= ih "12") (= "PM" dn))
                (if (> 10 (+ 12 (long (Double/valueOf ih))))
                  (str \0 (+ 12 (long (Double/valueOf ih))))
                  (+ 12 (long (Double/valueOf ih))))
                (and (= "12" ih) (= dn "AM")) "00"
                :else ih)]
    (format "%s:%s:%s" h m s)))
