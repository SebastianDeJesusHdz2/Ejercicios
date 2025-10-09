;programa para calcular el factorial de un numero.
(defn factorial [n]
  (if (<= n 1)
    1
    (* n (factorial (- n 1)))))

(defn -main[]
  (println "Ingrese un numero para calcular su factorial:")
  (let [input (read-line)
        num (Integer. input)]
    (println (str "El factorial de " num " es: "
(factorial num)))))

(-main)