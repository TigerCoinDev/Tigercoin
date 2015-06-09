Tigercoin - TGC, is a fork of Bitcoin version 0.8.99, with addition of super random blocks.

Proof of work with SHA256 is used as in Bitcoin. The following specifications are implemented:
	- Each normal block has 128 coins
	- 45 seconds block time
	- Difficulty retargets every 20 blocks (approximately 15 mins). 
	- mining payout will be halved every 3 months (every 172800 blocks)
	- Expected total mined coins will be 47,011,968 coins
	- 4 confirmations for transaction
	- 50 confirmations for minted blocks
	
	- Random bonus blocks are (on average):
		- 1 superblock of 512 coins every hour (1/80 chance) 
		- 1 superblock of 2048 coins every day (1/1920 chance)

	- The default ports are 15660(Connect) and 15661(RPC).

To encourage early adopters, in the first 3 days (1st 5760 blocks) all the payouts (including superblocks) will be doubled.

The official website is: tigercoin.info (under construction).


License
-------

Tigercoin is released under the terms of the MIT license. See `COPYING` for more
information or see http://opensource.org/licenses/MIT.
