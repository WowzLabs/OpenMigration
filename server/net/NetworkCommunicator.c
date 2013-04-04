/*
	

	Server will does following
	
	1. Open a socket on the server that listens to the UDP requests. (I’ve chosen 8888)
	2. Make a loop that handles the UDP requests and responses
	3. Inside the loop, check the received UPD packet to see if it’s valid
	4. Still inside the loop, send a response to the IP and Port of the received packet


	Client will do following.

	1. Open a socket on a random port.
	2. Try to broadcast to the default broadcast address (255.255.255.255)
	3. Loop over all the computer’s network interfaces and get their broadcast addresses
	4. Send the UDP packet inside the loop to the interface’s broadcast address
	5. Wait for a reply
	6. When we have a reply, check to see if the package is valid
	7. When it’s valid, get the package’s sender IP address; this is the server’s IP address
	8. CLOSE the socket! We don’t want to leave open random ports on someone else’s computer


	NOTE: we don’t close the socket on the server because the server will receive
	   and send UPD packets until the server is closed. Closing the socket on the server means
	   that we won’t be able to discover it any more.

*/
