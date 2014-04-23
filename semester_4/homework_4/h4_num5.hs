add :: Int -> [Int] -> [Int]
add x [] = [x]
add x (y:ys)
		| x > y = y : (add x ys)
		| otherwise = x:y:ys

do_loop :: [Int] -> IO ()
do_loop list = do
    putStr "\nEnter the command: \n"
    putStr "0 - exit\n"
    putStr "1 - add value\n"
    putStr "2 - remove value\n"
    putStr "3 - print\n> "

    command <- getLine
    case command of
        "0" -> putStrLn "bye!"
        "1"-> do
                    putStr "value to add > "
                    value <- readLn
                    do_loop $ add value list
        "2" -> do 
                    putStr "value to remove > "
                    value <- readLn
                    do_loop (filter (/= value) list)
        "3" -> do
                    putStrLn (show(list))
                    do_loop list
        _   -> do 
					putStr "Wrong command! Try again.\n"
					do_loop list

main = do
	do_loop []
