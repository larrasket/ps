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

;; https://www.hackerrank.com/challenges/three-month-preparation-kit-breaking-best-and-worst-records
(defn breakingRecords [scores]
  (loop [minscore (scores 0)
         maxscore (scores 0)
         mr 0
         ml 0
         s (rest scores)]
    (if (empty? s)
      [ml mr]
      (cond
        (> (first s) maxscore) (recur minscore (first s) mr (inc ml) (rest s))
        (< (first s) minscore) (recur (first s) maxscore (inc mr) ml (rest s))
        :else (recur minscore maxscore mr ml (rest s))))))

;; https://www.hackerrank.com/challenges/three-month-preparation-kit-camel-case
;; (require '[clojure.string :as str])
(defn camel-case-help [[o t r]]
  (cond (= o "S")
        (str/lower-case
         (cond (= t "M")
               (str/join #" " (str/split ((str/split r #"\(") 0) #"(?=[A-Z])"))
               (or (= t "C") (= t "V")) (str/join #" " (str/split r #"(?=[A-Z])"))))
        (= o "C")
        (cond
          (= t "M")
          (str/replace-first (apply str (mapv str/capitalize
                                              (str/split (str r "()") #" ")))
                             #"^." str/lower-case)
          (= t "V")
          (str/replace-first (apply str (mapv str/capitalize
                                              (str/split r #" ")))
                             #"^." str/lower-case)
          :else (apply str (mapv str/capitalize
                                 (str/split r #" "))))))

(defn camel-case []
  (let [i (read-line)]
    (println (camel-case-help (str/split i #"\;")))))

;; (loop [i (read-line)]
;;     (when i
;;       (println (camel-case-help (str/split i #"\;")))
;;       (recur (read-line))))

;; TODO https://www.hackerrank.com/challenges/three-month-preparation-kit-divisible-sum-pairs

;; https://www.hackerrank.com/challenges/three-month-preparation-kit-lonely-integer
;; better version:
;; (defn lonelyinteger [a]
;;   (->> (frequencies a) (filter #(= 1 (val %))) (ffirst)))

(defn lonelyinteger [a]
  (ffirst
   (filter #(not= (first %)
                  (first (rest %)))
           (partition-all 2 (sort a)))))

(defn gradingStudents [grades]
  (loop
      [g grades
       i 0
       nf #(- 5 (mod % 5))]
    (cond
      (= i (count g)) g
      (and (< (nf (g i)) 3) (>= (g i) 38))
      (recur (assoc g i (+ (nf (g i) ) (g i)))
             (inc i)
             nf)
      :else (recur g (inc i) nf))))

;; https://www.hackerrank.com/challenges/three-month-preparation-kit-diagonal-difference
(defn diagonalDifference [arr]
  (loop
      [i 0
       j (- (count arr) 1)
       l 0
       r 0
       labs #(if (< % 0) (* % -1) %)]
    (if (>= i (count arr))
      (labs (- l r))
      (recur (inc i) (dec j) (+ l ((arr i) i)) (+ r ((arr i) j)) labs))))

;; https://www.hackerrank.com/challenges/three-month-preparation-kit-countingsort1
(defn countingSort [arr]
  (loop [freq (frequencies arr)
         i 0
         res []]
    (if (= i 100)
      res
      (recur freq (inc i) (conj res (or (freq i) 0))))))
