xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 88;
 -228.68892;0.26140;900.01379;,
 -235.09245;0.26140;1633.92871;,
 -240.77538;16.68390;1627.60242;,
 -234.20972;16.68390;898.30640;,
 236.58189;16.68390;1631.52625;,
 243.14813;16.68390;902.22913;,
 231.19341;0.26140;1637.75562;,
 237.59811;0.26140;903.83954;,
 -258.97043;0.27775;177.68637;,
 -254.16702;0.27775;1633.76294;,
 -254.16702;31.32170;1633.76294;,
 -258.97043;31.32170;177.68637;,
 -223.73129;31.32170;1634.02783;,
 -228.53453;31.32170;177.95139;,
 -223.73129;0.27775;1634.02783;,
 -228.53453;0.27775;177.95139;,
 -254.16702;0.27775;1633.76294;,
 -258.97043;0.27775;177.68637;,
 -223.73129;0.27775;1634.02783;,
 -223.73129;31.32170;1634.02783;,
 -228.53453;0.27775;177.95139;,
 -228.53453;31.32170;177.95139;,
 -224.51115;0.26140;172.47949;,
 -230.91469;0.26140;906.39410;,
 -236.59761;16.68390;900.06769;,
 -230.03195;16.68390;170.77209;,
 242.36749;16.68390;903.99152;,
 248.93373;16.68390;174.69489;,
 236.97900;0.26140;910.22101;,
 243.38371;0.26140;176.30536;,
 -249.98926;0.27775;906.22833;,
 -219.55353;0.27775;906.49323;,
 -219.55353;31.32170;906.49323;,
 -249.98926;31.32170;906.22833;,
 -227.00554;0.26140;-554.73389;,
 -227.00430;0.26140;179.20822;,
 -227.56850;16.68390;172.93161;,
 -227.36725;16.68390;-556.39343;,
 248.01152;16.68390;172.93286;,
 248.21323;16.68390;-556.39325;,
 242.67763;0.26140;179.20908;,
 242.67752;0.26140;-554.73425;,
 -246.07962;0.27775;179.20883;,
 -215.64273;0.27775;179.20807;,
 -215.64273;31.32170;179.20807;,
 -246.07962;31.32170;179.20883;,
 -224.75781;0.26140;-1283.87476;,
 -224.75659;0.26140;-549.93213;,
 -230.49463;16.68390;-556.20874;,
 -230.29333;16.68390;-1285.53369;,
 246.36987;16.68390;-556.20752;,
 246.57162;16.68390;-1285.53345;,
 241.03592;0.26140;-549.93127;,
 241.03583;0.26140;-1283.87463;,
 -243.83191;0.27775;-549.93127;,
 -213.39502;0.27775;-549.93213;,
 -213.39502;31.32170;-549.93213;,
 -243.83191;31.32170;-549.93127;,
 -224.72206;0.26140;-1641.74561;,
 -221.38277;0.26140;-1269.59692;,
 -227.22935;16.68390;-1275.77234;,
 -230.28566;16.68390;-1643.30786;,
 247.21429;16.68390;-1283.61597;,
 244.15848;16.68390;-1651.15259;,
 241.99072;0.26140;-1277.24768;,
 238.65253;0.26140;-1649.39734;,
 -240.45518;0.27775;-1269.26318;,
 -210.02293;0.27775;-1269.79517;,
 -210.02293;31.32170;-1269.79517;,
 -240.45518;31.32170;-1269.26318;,
 -228.68892;0.26140;-924.87335;,
 -235.09245;0.26140;-190.95850;,
 -240.77538;16.68390;-197.28473;,
 -234.20972;16.68390;-926.58075;,
 -258.97043;0.27775;-1647.20068;,
 -254.16701;0.27775;-191.12433;,
 -254.16701;31.32170;-191.12433;,
 -258.97043;31.32170;-1647.20068;,
 -223.73129;31.32170;-190.85938;,
 -228.53453;31.32170;-1646.93555;,
 -223.73129;0.27775;-190.85938;,
 -228.53453;0.27775;-1646.93555;,
 -254.16701;0.27775;-191.12433;,
 -258.97043;0.27775;-1647.20068;,
 -223.73129;0.27775;-190.85938;,
 -223.73129;31.32170;-190.85938;,
 -228.53453;0.27775;-1646.93555;,
 -228.53453;31.32170;-1646.93555;;
 
 47;
 4;0,1,2,3;,
 4;3,2,4,5;,
 4;5,4,6,7;,
 4;7,6,1,0;,
 4;1,6,4,2;,
 4;7,0,3,5;,
 4;8,9,10,11;,
 4;11,10,12,13;,
 4;13,12,14,15;,
 4;15,14,16,17;,
 4;9,18,19,10;,
 4;20,8,11,21;,
 4;22,23,24,25;,
 4;25,24,26,27;,
 4;27,26,28,29;,
 4;29,28,23,22;,
 4;23,28,26,24;,
 4;29,22,25,27;,
 4;30,31,32,33;,
 4;34,35,36,37;,
 4;37,36,38,39;,
 4;39,38,40,41;,
 4;41,40,35,34;,
 4;35,40,38,36;,
 4;41,34,37,39;,
 4;42,43,44,45;,
 4;46,47,48,49;,
 4;49,48,50,51;,
 4;51,50,52,53;,
 4;53,52,47,46;,
 4;47,52,50,48;,
 4;53,46,49,51;,
 4;54,55,56,57;,
 4;58,59,60,61;,
 4;61,60,62,63;,
 4;63,62,64,65;,
 4;65,64,59,58;,
 4;59,64,62,60;,
 4;65,58,61,63;,
 4;66,67,68,69;,
 4;70,71,72,73;,
 4;74,75,76,77;,
 4;77,76,78,79;,
 4;79,78,80,81;,
 4;81,80,82,83;,
 4;75,84,85,76;,
 4;86,74,77,87;;
 
 MeshMaterialList {
  2;
  47;
  1,
  1,
  1,
  1,
  1,
  1,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  1,
  1,
  1,
  1,
  1,
  0,
  1,
  1,
  1,
  1,
  1,
  1,
  0,
  1,
  1,
  1,
  1,
  1,
  1,
  0,
  1,
  1,
  1,
  1,
  1,
  1,
  0,
  1,
  0,
  0,
  0,
  0,
  0,
  0;;
  Material {
   0.160000;0.160000;0.160000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "C:\\Users\\student\\Downloads\\brick1_15_sume.jpg";
   }
  }
 }
 MeshNormals {
  45;
  -0.945800;-0.324642;-0.008384;,
  0.000000;1.000000;0.000000;,
  0.949333;-0.314159;0.008416;,
  -0.999995;0.000000;0.003299;,
  0.999995;0.000000;-0.003299;,
  0.000000;-1.000000;-0.000000;,
  -0.007672;0.356998;0.934074;,
  0.008169;-0.100509;-0.994903;,
  -0.008703;0.000000;0.999962;,
  0.008707;0.000000;-0.999962;,
  -0.945800;-0.324642;-0.008384;,
  0.000000;1.000000;0.000000;,
  0.949333;-0.314159;0.008416;,
  -0.008703;0.000000;0.999962;,
  0.000000;-1.000000;0.000000;,
  -0.007646;0.357008;0.934070;,
  0.008142;-0.100511;-0.994903;,
  -0.999602;-0.028191;-0.000137;,
  0.000000;1.000000;0.000000;,
  0.949371;-0.314157;0.000131;,
  0.000025;0.000000;1.000000;,
  0.000000;-1.000000;-0.000000;,
  -0.000002;0.357000;0.934104;,
  -0.000000;-0.100525;-0.994935;,
  -0.945836;-0.324646;-0.000130;,
  0.000000;1.000000;0.000000;,
  0.949370;-0.314161;0.000131;,
  0.000028;0.000000;1.000000;,
  0.000000;-1.000000;-0.000000;,
  -0.000002;0.357000;0.934104;,
  0.000000;-0.100501;-0.994937;,
  -0.945205;-0.326375;0.008170;,
  0.000000;1.000000;0.000000;,
  0.949924;-0.312372;-0.008210;,
  0.017478;0.000000;0.999847;,
  0.000000;-1.000000;-0.000000;,
  0.015431;0.356989;0.933981;,
  -0.016438;-0.100512;-0.994800;,
  -0.945800;-0.324642;-0.008384;,
  -0.999995;0.000000;0.003299;,
  0.000000;1.000000;0.000000;,
  0.999995;0.000000;-0.003299;,
  0.000000;-1.000000;-0.000000;,
  -0.008705;0.000000;0.999962;,
  0.008711;0.000000;-0.999962;;
  47;
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;5,5,5,5;,
  4;6,6,6,6;,
  4;7,7,7,7;,
  4;3,3,3,3;,
  4;1,1,1,1;,
  4;4,4,4,4;,
  4;5,5,5,5;,
  4;8,8,8,8;,
  4;9,9,9,9;,
  4;10,10,10,10;,
  4;11,11,11,11;,
  4;12,12,12,12;,
  4;14,14,14,14;,
  4;15,15,15,15;,
  4;16,16,16,16;,
  4;13,13,13,13;,
  4;17,17,17,17;,
  4;18,18,18,18;,
  4;19,19,19,19;,
  4;21,21,21,21;,
  4;22,22,22,22;,
  4;23,23,23,23;,
  4;20,20,20,20;,
  4;24,24,24,24;,
  4;25,25,25,25;,
  4;26,26,26,26;,
  4;28,28,28,28;,
  4;29,29,29,29;,
  4;30,30,30,30;,
  4;27,27,27,27;,
  4;31,31,31,31;,
  4;32,32,32,32;,
  4;33,33,33,33;,
  4;35,35,35,35;,
  4;36,36,36,36;,
  4;37,37,37,37;,
  4;34,34,34,34;,
  4;38,38,38,38;,
  4;39,39,39,39;,
  4;40,40,40,40;,
  4;41,41,41,41;,
  4;42,42,42,42;,
  4;43,43,43,43;,
  4;44,44,44,44;;
 }
 MeshTextureCoords {
  88;
  0.318045;-1.046266;,
  0.312699;-2.310702;,
  0.308007;-2.299308;,
  0.313486;-1.042829;,
  0.702209;-2.306146;,
  0.707689;-1.049666;,
  0.697759;-2.317371;,
  0.703105;-1.052933;,
  0.375000;1.000000;,
  0.625000;1.000000;,
  0.625000;0.750000;,
  0.375000;0.750000;,
  0.625000;0.500000;,
  0.375000;0.500000;,
  0.625000;0.250000;,
  0.375000;0.250000;,
  0.625000;0.000000;,
  0.375000;0.000000;,
  0.875000;1.000000;,
  0.875000;0.750000;,
  0.125000;1.000000;,
  0.125000;0.750000;,
  0.321552;0.207178;,
  0.316206;-1.057258;,
  0.311514;-1.045864;,
  0.316993;0.210614;,
  0.707044;-1.052702;,
  0.712524;0.203777;,
  0.702594;-1.063928;,
  0.707940;0.200510;,
  0.625000;1.000000;,
  0.875000;1.000000;,
  0.875000;0.750000;,
  0.625000;0.750000;,
  0.319549;1.460069;,
  0.319493;0.195585;,
  0.319027;0.206893;,
  0.319251;1.463423;,
  0.711762;0.206813;,
  0.711986;1.463344;,
  0.707357;0.195507;,
  0.707414;1.459993;,
  0.625000;1.000000;,
  0.875000;1.000000;,
  0.875000;0.750000;,
  0.625000;0.750000;,
  0.321462;2.716281;,
  0.321406;1.451796;,
  0.316668;1.463105;,
  0.316891;2.719634;,
  0.710464;1.463025;,
  0.710687;2.719556;,
  0.706058;1.451718;,
  0.706116;2.716205;,
  0.625000;1.000000;,
  0.875000;1.000000;,
  0.875000;0.750000;,
  0.625000;0.750000;,
  0.321520;3.332844;,
  0.324248;2.691682;,
  0.319421;2.702816;,
  0.316926;3.336031;,
  0.711218;2.716252;,
  0.708723;3.349469;,
  0.706904;2.704787;,
  0.704176;3.345952;,
  0.625000;1.000000;,
  0.875000;1.000000;,
  0.875000;0.750000;,
  0.625000;0.750000;,
  0.318188;2.097770;,
  0.312842;0.833334;,
  0.308150;0.844728;,
  0.313629;2.101207;,
  0.375000;1.000000;,
  0.625000;1.000000;,
  0.625000;0.750000;,
  0.375000;0.750000;,
  0.625000;0.500000;,
  0.375000;0.500000;,
  0.625000;0.250000;,
  0.375000;0.250000;,
  0.625000;0.000000;,
  0.375000;0.000000;,
  0.875000;1.000000;,
  0.875000;0.750000;,
  0.125000;1.000000;,
  0.125000;0.750000;;
 }
}
