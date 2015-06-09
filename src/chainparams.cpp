// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "assert.h"

#include "chainparams.h"
#include "core.h"
#include "protocol.h"
#include "util.h"

//
// Main network
//

unsigned int pnSeed[] =
{
    0x12346678
};

class CMainParams : public CChainParams {
public:
    CMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        pchMessageStart[0] = 0xfa;
        pchMessageStart[1] = 0xb5;
        pchMessageStart[2] = 0xdf;
        pchMessageStart[3] = 0xdb;
        vAlertPubKey = ParseHex("04777702888840aaffffde8442ebecedf5b095cdbb9bc716bda9110971b28a49e0ead8564ff0db22209e0374782c093bb899692d524e9d6a6956e7c5ecbcd68284");
        nDefaultPort = 15660;
        nRPCPort = 15661;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 20);
        nSubsidyHalvingInterval = 172800;

        // Build the genesis block. Note that the output of the genesis coinbase cannot
        // be spent as it did not originally exist in the database.
  
        const char* pszTimestamp = "9/05/2013 @ 5:10PM: Virgin Galactic's SpaceShipTwo Succeeds In Second Rocket-Powered Flight.";
        CTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CBigNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 128 * COIN;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("04678aaaa0fe55482f1967f1a67130b7105cd6a000e03909a67962e0ea1f61deb649f6bc3f4cef38c4f35504e51ec112de5c384df7ba0b8d578a4c702b6bf11d5f") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1378495795;
        genesis.nBits    = 0x1e0fffff;
        genesis.nNonce   = 285333548;
        
        //// debug print
        hashGenesisBlock = genesis.GetHash();
		/*
        while (hashGenesisBlock > bnProofOfWorkLimit.getuint256())
		{
            if (++genesis.nNonce==0) break;
            hashGenesisBlock = genesis.GetHash();
        }
		*/
		
        printf("hashGenesisBlock = %s\n", hashGenesisBlock.ToString().c_str());
        printf("hashMerkleRoot = %s\n", genesis.hashMerkleRoot.ToString().c_str());
        printf("%x\n", bnProofOfWorkLimit.GetCompact());
        genesis.print();
        
        
        assert(hashGenesisBlock == uint256("0x000000e02a1a674989cc114a50fea6d46e9fd18620129418589364b75f3292ac"));
        assert(genesis.hashMerkleRoot == uint256("0xaee5ee4074090a7564fd6a51e16a9e0ef4656d14fe4798be3e13d085cbbf7577"));

        vSeeds.push_back(CDNSSeedData("bitcoin.sipa.be", "seed.bitcoin.sipa.be"));
        vSeeds.push_back(CDNSSeedData("bluematt.me", "dnsseed.bluematt.me"));
		vSeeds.push_back(CDNSSeedData("xf2.org", "bitseed.xf2.org"));
        vSeeds.push_back(CDNSSeedData("dashjr.org", "dnsseed.bitcoin.dashjr.org"));

        base58Prefixes[PUBKEY_ADDRESS] = 127;
        base58Prefixes[SCRIPT_ADDRESS] = 9;
        base58Prefixes[SECRET_KEY] = 224;

        // Convert the pnSeeds array into usable address objects.
        for (unsigned int i = 0; i < ARRAYLEN(pnSeed); i++)
        {
            // It'll only connect to one or two seed nodes because once it connects,
            // it'll get a pile of addresses with newer timestamps.
            // Seed nodes are given a random 'last seen time' 
            const int64 nTwoDays = 2 * 24 * 60 * 60;
            struct in_addr ip;
            memcpy(&ip, &pnSeed[i], sizeof(ip));
            CAddress addr(CService(ip, GetDefaultPort()));
            addr.nTime = GetTime() - GetRand(nTwoDays) - nTwoDays;
            vFixedSeeds.push_back(addr);
        }
    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


//
// Testnet (v3)
//
class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        pchMessageStart[0] = 0x05;
        pchMessageStart[1] = 0xfe;
        pchMessageStart[2] = 0xa9;
        pchMessageStart[3] = 0x01;
        vAlertPubKey = ParseHex("04303390343f91cc401d56d68b123028bf52e5fca1939df127f63c6467cdf9c8e2c14b61104cf817d0b780da337893ecc4aaff1309e536162dabbdb45200ca2b0a");
        nDefaultPort = 28077;
        nRPCPort = 28078;
        strDataDir = "testnet";

        // Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime = 1378495253;
        genesis.nNonce = 0;
        
        
        //// debug print
        hashGenesisBlock = genesis.GetHash();
        //while (hashGenesisBlock > bnProofOfWorkLimit.getuint256()){
        //    if (++genesis.nNonce==0) break;
        //   hashGenesisBlock = genesis.GetHash();
        //}

        printf("hashGenesisBlock-testnet = %s\n", hashGenesisBlock.ToString().c_str());
        printf("hashMerkleRoot-testnet = %s\n", genesis.hashMerkleRoot.ToString().c_str());
        genesis.print();
        
        assert(hashGenesisBlock == uint256("0xa6e7e253dd963065e18841baf1f2b3617ff4ee144132e51f86d16096f55f0040"));

        vFixedSeeds.clear();
        vSeeds.clear();
        // vSeeds.push_back(CDNSSeedData("tigercoin.test", "test.tigercoin.org"));

        base58Prefixes[PUBKEY_ADDRESS] = 77;
        base58Prefixes[SCRIPT_ADDRESS] = 177;
        base58Prefixes[SECRET_KEY] = 239;

    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;


//
// Regression test
//
class CRegTestParams : public CTestNetParams {
public:
    CRegTestParams() {
        pchMessageStart[0] = 0xfa;
        pchMessageStart[1] = 0x0f;
        pchMessageStart[2] = 0xa5;
        pchMessageStart[3] = 0x5a;
        nSubsidyHalvingInterval = 150;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 1);
        genesis.nTime = 1396688602;
        genesis.nBits = 0x207fffff;
        genesis.nNonce = 3;
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 28444;
        strDataDir = "regtest";
        
        //// debug print
        hashGenesisBlock = genesis.GetHash();
        //while (hashGenesisBlock > bnProofOfWorkLimit.getuint256()){
        //    if (++genesis.nNonce==0) break;
        //    hashGenesisBlock = genesis.GetHash();
        //}

        printf("%s\n", hashGenesisBlock.ToString().c_str());
        printf("%s\n", genesis.hashMerkleRoot.ToString().c_str());
        genesis.print();

        // assert(hashGenesisBlock == uint256("0x13d8d31dde96874006da503dd2b63fa68c698dc823334359e417aa3a92f80433"));

        vSeeds.clear();  // Regtest mode doesn't have any DNS seeds.

        base58Prefixes[PUBKEY_ADDRESS] = 0;
        base58Prefixes[SCRIPT_ADDRESS] = 5;
        base58Prefixes[SECRET_KEY] = 128;
    }

    virtual bool RequireRPCPassword() const { return false; }
    virtual Network NetworkID() const { return CChainParams::REGTEST; }
};
static CRegTestParams regTestParams;

static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        case CChainParams::REGTEST:
            pCurrentParams = &regTestParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {
    bool fRegTest = GetBoolArg("-regtest", false);
    bool fTestNet = GetBoolArg("-testnet", false);

    if (fTestNet && fRegTest) {
        return false;
    }

    if (fRegTest) {
        SelectParams(CChainParams::REGTEST);
    } else if (fTestNet) {
        SelectParams(CChainParams::TESTNET);
    } else {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
