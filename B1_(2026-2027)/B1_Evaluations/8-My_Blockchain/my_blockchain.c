








/*

Submit directory: . Submit files: Makefile - *.c - *.h

Command Name
my_blockchain — Blockchain: the Beginning

Synopsis: my_blockchain

Description
Blockchain is a command that allows for the creation and management of a blockchain. When the program starts (it loads a backup if there is one) then a prompt appears. This prompt allows to execute commands. When the commands are successful they display ok and if not, nok: info where info is an error message (see below).

Command	Description
add node nid	Add a nid identifier to the blockchain node.
rm node nid...	Remove nodes from the blockchain with a nid identifier. If nid is *, then all nodes are impacted.
add block bid nid...	Add a bid identifier block to nodes identified by nid. If nid is *, then all nodes are impacted.
rm block bid nid...	Remove the bid identified blocks from nodes identified by nid.
ls	List all nodes by their identifiers. The option -l attaches the blocks bid's associated with each node.
sync	Synchronize all of the nodes with each other. Upon issuing this command, all of the nodes are composed of the same blocks.
quit	Save and leave the blockchain.
Prompt
The blockchain prompt must display (see example below):

a [ character
a first letter that indicates the state of synchronization of the chain: s if the blockchain is synchronized, - if the blockchain is not synchronized
n number of nodes in the chain
the ]> string (with a space)
Error messages
Code	Message
1	no more resources available on the computer
2	this node already exists
3	this block already exists
4	node doesn't exist
5	block doesn't exist
6	command not found
Example
$>my_blockchain
No Backup Found: Starting New Blockchain
[s0]> add node 12
OK
[s1]> add block 21 *
OK
[s1]> add node 13
OK
[-2]> sync
OK
[s2]> ls -l
12: 21
13: 21
[s2]> quit
Backing up blockchain...
$>my_blockchain
Restoring From Backup
[s2]> ls -l
12: 21
13: 21
[s2]>
Technical information
You must create a Makefile, and the output is the command itself.

NID is an integer, BID is a string.

You can use:

malloc(3)   free(3)   printf(3)   write(2)
open(2)     read(2)   close(2)
Multiline macros are forbidden.
Include another .c is forbidden.
Macros with logic (while/if/variables/...) are forbidden.

🧪 Test ideas to consider — My Blockchain
Input ./my_blockchain (first launch, no backup file)
Expected Output
No Backup Found: Starting New Blockchain
[s0]> 
Input add node 12, then add node 12 again
Expected Output OK, then nok: this node already exists (prompt stays [s1]>)
Input add block 21 99 (node 99 does not exist)
Expected Output nok: node doesn't exist
Input add block 21 12 twice on the same node
Expected Output OK, then nok: this block already exists
Input rm block 42 12 (block 42 not on node 12)
Expected Output nok: block doesn't exist
Input hello (unknown command)
Expected Output nok: command not found
Input add node 13 after blocks were added, then sync
Expected Output Prompt goes to [-2]>, then back to [s2]> after sync
💡 The "s" / "-" letter must be recomputed after every command, not only after sync
Input ls vs ls -l
Expected Output ls: node ids only / ls -l: "12: 21" format with blocks
Input rm node *
Expected Output OK, prompt back to [s0]> (all memory freed)
Input quit, then relaunch ./my_blockchain
Expected Output Restoring From Backup, same prompt and same ls -l as before quitting
💡 Also restore the sync state: an unsynchronized chain must come back as [-n]>
Input Ctrl+D (end of input) at the prompt
Expected Output Behavior to define, but must not loop forever or crash

*/