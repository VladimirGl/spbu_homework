data Printed =  Book { 
					title :: String,
					author :: String,
					price :: Int 
					}
				|
				Magazine {
					title :: String,
					year :: Int,
					issue_number :: Int,
					price :: Int
					}
					
printed_list_price :: [Printed] -> Int
printed_list_price = foldr ((+) . price) 0
