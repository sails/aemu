/*
 * This file is part of PRO ONLINE.

 * PRO ONLINE is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * PRO ONLINE is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PRO ONLINE. If not, see <http://www.gnu.org/licenses/ .
 */

#ifndef _PACKETS_H_
#define _PACKETS_H_

#define OPCODE_PING 0
//#define OPCODE_LOGIN 1
// not allow other ppsspp login
#define OPCODE_LOGIN 111
#define OPCODE_CONNECT 2
#define OPCODE_DISCONNECT 3
#define OPCODE_SCAN 4
#define OPCODE_SCAN_COMPLETE 5
#define OPCODE_CONNECT_BSSID 6
#define OPCODE_CHAT 7

// PSP Product Code
#define PRODUCT_CODE_LENGTH 9


#define OPCODE_GAME_DATA 100


typedef struct
{
	// Game Product Code (ex. ULUS12345)
	char data[PRODUCT_CODE_LENGTH];
} __attribute__((packed)) SceNetAdhocctlProductCode;

// Basic Packet
typedef struct
{
	uint8_t opcode;
} __attribute__((packed)) SceNetAdhocctlPacketBase;

// C2S Login Packet
typedef struct
{
	SceNetAdhocctlPacketBase base;
	SceNetEtherAddr mac;
	SceNetAdhocctlNickname name;
	SceNetAdhocctlProductCode game;
} __attribute__((packed)) SceNetAdhocctlLoginPacketC2S;

// C2S Connect Packet
typedef struct
{
	SceNetAdhocctlPacketBase base;
	SceNetAdhocctlGroupName group;
} __attribute__((packed)) SceNetAdhocctlConnectPacketC2S;

// C2S Chat Packet
typedef struct
{
	SceNetAdhocctlPacketBase base;
	char message[64];
} __attribute__((packed)) SceNetAdhocctlChatPacketC2S;

// S2C Connect Packet
typedef struct
{
	SceNetAdhocctlPacketBase base;
	SceNetAdhocctlNickname name;
	SceNetEtherAddr mac;
	uint32_t ip;
} __attribute__((packed)) SceNetAdhocctlConnectPacketS2C;

// S2C Disconnect Packet
typedef struct
{
	SceNetAdhocctlPacketBase base;
	uint32_t ip;
        SceNetEtherAddr mac;
} __attribute__((packed)) SceNetAdhocctlDisconnectPacketS2C;

// S2C Scan Packet
typedef struct
{
	SceNetAdhocctlPacketBase base;
	SceNetAdhocctlGroupName group;
	SceNetEtherAddr mac;
} __attribute__((packed)) SceNetAdhocctlScanPacketS2C;

// S2C Connect BSSID Packet
typedef struct
{
	SceNetAdhocctlPacketBase base;
	SceNetEtherAddr mac;
} __attribute__((packed)) SceNetAdhocctlConnectBSSIDPacketS2C;

// S2C Chat Packet
typedef struct
{
	SceNetAdhocctlChatPacketC2S base;
	SceNetAdhocctlNickname name;
} __attribute__((packed)) SceNetAdhocctlChatPacketS2C;


// c2c Packet
typedef struct {
    SceNetAdhocctlPacketBase base;
    uint8_t additional_opcode;
    SceNetEtherAddr smac;
    SceNetEtherAddr dmac;
    uint32_t ip;
    uint16_t sport;
    uint16_t dport;
    int len;
    char data[1];
} __attribute__((packed)) SceNetAdhocctlGameDataPacketC2C;


#endif
