#### VPN

Resource retrieved from [https://technet.microsoft.com/en-us/library/cc779919(v=ws.10).aspx](https://technet.microsoft.com/en-us/library/cc779919(v=ws.10\).aspx)


##### Archtecture
To establish a secure private network over an unsecured network, such as the Internet.

VPN encrypts and encapsulate private network traffic and moving it through an intermediate network. Packets that might be intercepted on the shared public network are indecipherable without the correct encryption keys.

Data is also encapsulated with IP header containing routing information.

---

##### Two Types of VPN

###### Remote Access VPN

Senario: A client wants to connect to a private network from a remote location

The VPN server provides access to the resrouces of the network to which the the VPN server is connected. The packets sent across the VPN connection orignate at the VPN client.

VPN client authenticate itself to the VPN server and VPN server authenticate itself to the VPN client.
 
![alt text](https://i-technet.sec.s-msft.com/dynimg/IC196810.gif)

###### Site to Site VPN

Site-to-Site VPN connects two private networks. A routed VPN connection acrosss the internet logically operates as a dedicated Wide Area Network (WAN) link.

The VPN server provides a routed connection to the network to which the VPN server is attached. The packets would be sent from either router across the VPN connection.

The calling router and answering router would do mutual authentication on each other.

Inline-style: 
![alt text](https://i-technet.sec.s-msft.com/dynimg/IC196811.gif)