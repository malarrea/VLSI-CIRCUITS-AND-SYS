prompt x = do
    putStrLn x
    number <- getLine
    return number



main = do
  putStrLn "KL ALGORITHM [HEURISTIC] : LOGAN CAMPBELL \n "
  putStrLn "GRAPH ( VERTEX [set], EDGE [set] ) \n"
  nodes <- prompt "Enter Node(s): "
  print $ (read nodes :: Int)
  edges <- prompt "Enter Edge(s): "
  print $ (read edges :: Int)
-- can't define graph for vsli design because
-- haskell is a lazy programming language. therefore
-- have to use another language...

-- you could represent using "typing the knot"
-- or other representation that require recursion.
