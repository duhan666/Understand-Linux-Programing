
#!/bin/bash



while true 
do
	who | sort > prev
	sleep 2
	who | sort > curr
	echo "logged out"
	comm  prev curr
	echo "logged in"
	comm  prev curr
	mv curr prev
done