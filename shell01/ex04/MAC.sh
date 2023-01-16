ifconfig| grep 'ether' | awk '$1=="ether" {print $2}' 
