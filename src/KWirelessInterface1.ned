//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package ops;

simple KWirelessInterface1
{
    parameters:
        string ownMACAddress;
        string interfaceTypeName = default("wireless");
        double wirelessRange @unit(m) = default(30m);
        double neighbourScanInterval @unit(s) = default(1s);
        double bandwidthBitRate @unit(bps) = default(100000bps); // 100 Kbps
        int wirelessHeaderSize @unit(byte) = default(16byte); // 32byte = 802.11 a/b/g, 16byte = BT
        double advertisementInterval @unit(s) = default(100ms); //I added
       	double beaconTime @unit(s); //I added
        //volatile double advertisementDelay @unit(s); //I added
        volatile double randomDelay @unit(s); //I added
        double timingDelay @unit(s) = default(10ms);

        // OMNET RNG for random numbers
        // not used - for future use
        int usedRNG = default(0);        

        // icon
        @display("i=device/card");

        // statistics and signals
        @signal[linkNeighSize](type=long);
        @signal[linkNeighSizeCount](type=long);
        @signal[linkContactDuration](type=simtime_t);
        @signal[linkContactDurationCount](type=long);
        
        @signal[linkPacketProbability](type=double);
        @signal[linkPacketProbabilityCount](type=long);
        @signal[delay](type=simtime_t);
        @signal[linkNonSuccIdProb](type = double);

    gates:
        // interface to the upper layer (which may be the link adaptation layer)
        input upperLayerIn;
        output upperLayerOut;

        // interface to the lower layer (which may be the physical layer)
        // there is no lowerLayerOut as packets are sent directly to
        // emulate wireless communications (uses @directIn)
        input lowerLayerIn;
}

