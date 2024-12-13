simulate :: Int -> IO ()

simulate 1 = do
  putStrLn "1"

simulate n = do
  putStrLn (show n)
  if even n then simulate (n `div` 2) else simulate (3*n+1)

main :: IO ()
main = do
  n <- (readLn :: IO Int)
  simulate n
