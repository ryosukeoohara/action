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
 134;
 -2.73480;-12.05765;3.05790;,
 -0.00000;-12.03478;4.17647;,
 -0.00000;-7.98127;4.09356;,
 -2.73480;-8.00415;2.97499;,
 2.73480;-12.05765;3.05790;,
 2.73480;-8.00415;2.97499;,
 3.86759;-12.11289;0.35745;,
 3.86759;-8.05938;0.27454;,
 2.73480;-12.16813;-2.34301;,
 2.73480;-8.11462;-2.42592;,
 0.00000;-12.19100;-3.46158;,
 0.00000;-8.13749;-3.54449;,
 -2.73480;-12.16813;-2.34301;,
 -2.73480;-8.11462;-2.42592;,
 -3.86759;-12.11289;0.35745;,
 -3.86759;-8.05938;0.27454;,
 -2.73480;-12.05765;3.05790;,
 -2.73480;-8.00415;2.97499;,
 -0.00000;-7.00299;4.00486;,
 -2.73480;-7.02587;2.88630;,
 2.73480;-7.02587;2.88630;,
 3.86759;-7.08110;0.18584;,
 2.73480;-7.13633;-2.51462;,
 0.00000;-7.15922;-3.63319;,
 -2.73480;-7.13633;-2.51462;,
 -3.86759;-7.08110;0.18584;,
 -2.73480;-7.02587;2.88630;,
 -0.00000;-5.42853;4.18443;,
 -2.64527;-5.45296;2.98966;,
 2.64527;-5.45296;2.98966;,
 3.85524;-5.51196;0.10523;,
 2.64527;-5.57096;-2.77920;,
 0.00000;-5.59540;-3.97397;,
 -2.64527;-5.57096;-2.77920;,
 -3.85524;-5.51196;0.10523;,
 -2.64527;-5.45296;2.98966;,
 -0.00000;-0.70651;6.73424;,
 -3.49555;-0.68183;5.34252;,
 3.13315;-0.60876;5.16863;,
 3.42646;-0.43605;0.01029;,
 2.20092;1.22121;-2.50457;,
 0.00000;1.19377;-4.39410;,
 -2.42990;1.22018;-3.10313;,
 -3.42646;-0.83372;0.00954;,
 -3.49555;-0.68183;5.34252;,
 -0.00000;-12.03478;4.17647;,
 -2.73480;-12.05765;3.05790;,
 0.00000;-12.22612;-0.06384;,
 2.73480;-12.05765;3.05790;,
 3.86759;-12.11289;0.35745;,
 2.73480;-12.16813;-2.34301;,
 0.00000;-12.19100;-3.46158;,
 -2.73480;-12.16813;-2.34301;,
 -3.86759;-12.11289;0.35745;,
 -3.49555;-0.68183;5.34252;,
 -0.00000;-0.70651;6.73424;,
 0.00000;3.87531;4.97997;,
 3.13315;-0.60876;5.16863;,
 3.42646;-0.43605;0.01029;,
 2.20092;1.22121;-2.50457;,
 1.79927;2.84816;-1.20272;,
 0.00000;1.19377;-4.39410;,
 0.00000;3.86103;-2.54232;,
 -2.03347;2.89817;-1.47788;,
 -2.42990;1.22018;-3.10313;,
 -3.42646;-0.83372;0.00954;,
 -1.75281;-18.84173;2.64129;,
 -0.03177;-18.84173;2.89060;,
 -0.03177;-16.82689;3.63311;,
 -2.38974;-16.82689;2.65640;,
 1.72457;-18.84173;2.63912;,
 2.32620;-16.82689;2.65640;,
 3.11333;-18.84173;0.41211;,
 3.30290;-16.82689;0.29844;,
 2.19984;-18.84173;-1.83890;,
 2.32620;-16.82689;-2.05953;,
 -0.03177;-18.84173;-3.17670;,
 -0.03177;-16.82689;-3.03623;,
 0.94907;-18.84173;-2.83046;,
 -2.38974;-16.82689;-2.05953;,
 -2.08878;-18.84173;-1.82118;,
 -0.92823;-18.84173;-2.82190;,
 -2.95387;-18.84173;0.29844;,
 -3.36644;-16.82689;0.29844;,
 -1.75281;-18.84173;2.64129;,
 -2.38974;-16.82689;2.65640;,
 -0.03177;-14.81206;3.63311;,
 -2.38974;-14.81206;2.65640;,
 2.32620;-14.81206;2.65640;,
 3.30290;-14.81206;0.29844;,
 2.32620;-14.81206;-2.05953;,
 -0.03177;-14.81206;-3.03623;,
 -2.38974;-14.81206;-2.05953;,
 -3.36644;-14.81206;0.29844;,
 -2.38974;-14.81206;2.65640;,
 -0.03177;-12.79722;3.63311;,
 -2.38974;-12.79722;2.65640;,
 2.32620;-12.79722;2.65640;,
 3.30290;-12.79722;0.29844;,
 2.32620;-12.79722;-2.05953;,
 -0.03177;-12.79722;-3.03623;,
 -2.38974;-12.79722;-2.05953;,
 -3.36644;-12.79722;0.29844;,
 -2.38974;-12.79722;2.65640;,
 -0.03177;-10.78238;3.63311;,
 -2.38974;-10.78238;2.65640;,
 2.32620;-10.78238;2.65640;,
 3.30290;-10.78238;0.29844;,
 2.32620;-10.78238;-2.05953;,
 -0.03177;-10.78238;-3.03623;,
 -2.38974;-10.78238;-2.05953;,
 -3.36644;-10.78238;0.29844;,
 -2.38974;-10.78238;2.65640;,
 -0.03177;-18.84173;2.89060;,
 -1.75281;-18.84173;2.64129;,
 -0.03177;-20.96700;-0.30648;,
 1.72457;-18.84173;2.63912;,
 3.11333;-18.84173;0.41211;,
 2.19984;-18.84173;-1.83890;,
 0.94907;-18.84173;-2.83046;,
 -0.03177;-18.84173;-3.17670;,
 -0.03177;-19.87729;-2.61618;,
 -2.08878;-18.84173;-1.82118;,
 -0.92823;-18.84173;-2.82190;,
 -2.95387;-18.84173;0.29844;,
 -2.38974;-10.78238;2.65640;,
 -0.03177;-10.78238;3.63311;,
 -0.03177;-10.78238;0.29844;,
 2.32620;-10.78238;2.65640;,
 3.30290;-10.78238;0.29844;,
 2.32620;-10.78238;-2.05953;,
 -0.03177;-10.78238;-3.03623;,
 -2.38974;-10.78238;-2.05953;,
 -3.36644;-10.78238;0.29844;;
 
 108;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,8,9,7;,
 4;8,10,11,9;,
 4;10,12,13,11;,
 4;12,14,15,13;,
 4;14,16,17,15;,
 4;3,2,18,19;,
 4;2,5,20,18;,
 4;5,7,21,20;,
 4;7,9,22,21;,
 4;9,11,23,22;,
 4;11,13,24,23;,
 4;13,15,25,24;,
 4;15,17,26,25;,
 4;19,18,27,28;,
 4;18,20,29,27;,
 4;20,21,30,29;,
 4;21,22,31,30;,
 4;22,23,32,31;,
 4;23,24,33,32;,
 4;24,25,34,33;,
 4;25,26,35,34;,
 4;28,27,36,37;,
 4;27,29,38,36;,
 4;29,30,39,38;,
 4;30,31,40,39;,
 4;31,32,41,40;,
 4;32,33,42,41;,
 4;33,34,43,42;,
 4;34,35,44,43;,
 3;45,46,47;,
 3;48,45,47;,
 3;49,48,47;,
 3;50,49,47;,
 3;51,50,47;,
 3;52,51,47;,
 3;53,52,47;,
 3;46,53,47;,
 3;54,55,56;,
 3;55,57,56;,
 3;57,58,56;,
 4;58,59,60,56;,
 3;61,62,59;,
 3;59,62,60;,
 3;62,56,60;,
 3;56,62,63;,
 3;62,61,63;,
 3;61,64,63;,
 4;64,65,56,63;,
 3;65,54,56;,
 4;66,67,68,69;,
 4;67,70,71,68;,
 4;70,72,73,71;,
 4;72,74,75,73;,
 3;76,77,78;,
 3;78,77,74;,
 3;77,75,74;,
 3;79,77,80;,
 3;80,77,81;,
 3;77,76,81;,
 4;80,82,83,79;,
 4;82,84,85,83;,
 4;69,68,86,87;,
 4;68,71,88,86;,
 4;71,73,89,88;,
 4;73,75,90,89;,
 4;75,77,91,90;,
 4;77,79,92,91;,
 4;79,83,93,92;,
 4;83,85,94,93;,
 4;87,86,95,96;,
 4;86,88,97,95;,
 4;88,89,98,97;,
 4;89,90,99,98;,
 4;90,91,100,99;,
 4;91,92,101,100;,
 4;92,93,102,101;,
 4;93,94,103,102;,
 4;96,95,104,105;,
 4;95,97,106,104;,
 4;97,98,107,106;,
 4;98,99,108,107;,
 4;99,100,109,108;,
 4;100,101,110,109;,
 4;101,102,111,110;,
 4;102,103,112,111;,
 3;113,114,115;,
 3;116,113,115;,
 3;117,116,115;,
 3;118,117,115;,
 3;118,115,119;,
 3;119,115,120;,
 3;115,121,120;,
 3;115,122,121;,
 3;121,122,120;,
 3;122,123,120;,
 3;124,122,115;,
 3;114,124,115;,
 3;125,126,127;,
 3;126,128,127;,
 3;128,129,127;,
 3;129,130,127;,
 3;130,131,127;,
 3;131,132,127;,
 3;132,133,127;,
 3;133,125,127;;
 
 MeshMaterialList {
  1;
  108;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data\\TEXTURE\\neet3.jpg";
   }
  }
 }
 MeshNormals {
  93;
  -0.703993;0.014523;0.710058;,
  0.000000;0.020450;0.999791;,
  0.703993;0.014523;0.710058;,
  1.000000;0.000000;0.000001;,
  0.703994;-0.014523;-0.710058;,
  0.000000;-0.020450;-0.999791;,
  -0.703994;-0.014523;-0.710058;,
  -1.000000;0.000000;0.000001;,
  -0.703903;0.039365;0.709205;,
  0.000000;0.055412;0.998464;,
  0.703903;0.039365;0.709205;,
  1.000000;-0.000000;0.000001;,
  0.703903;-0.039367;-0.709204;,
  0.000000;-0.055414;-0.998463;,
  -0.703903;-0.039367;-0.709204;,
  -1.000000;-0.000000;0.000001;,
  -0.707569;0.020102;0.706358;,
  0.000000;0.006639;0.999978;,
  0.707569;0.020102;0.706358;,
  0.999992;0.003932;-0.000098;,
  0.706537;-0.079870;-0.703155;,
  0.000000;-0.134331;-0.990937;,
  -0.706537;-0.079870;-0.703155;,
  -0.999992;0.003932;-0.000098;,
  -0.743415;-0.152170;0.651290;,
  0.012619;-0.282254;0.959257;,
  0.746463;-0.135252;0.651536;,
  0.998809;0.018188;-0.045274;,
  0.738162;-0.025378;-0.674146;,
  0.026990;-0.101461;-0.994473;,
  -0.727860;-0.046747;-0.684131;,
  -0.999207;0.005271;-0.039457;,
  -0.661895;-0.063786;0.746877;,
  0.033738;-0.064437;0.997351;,
  0.791389;0.139122;0.595272;,
  0.958444;0.283624;-0.030714;,
  0.782886;0.336089;-0.523578;,
  -0.058093;0.393329;-0.917561;,
  -0.781334;0.316974;-0.537629;,
  -0.964989;0.260525;-0.030385;,
  -0.000000;-0.999826;0.018654;,
  0.036822;0.357321;0.933255;,
  0.616268;0.671384;-0.411652;,
  -0.636460;0.686170;-0.352265;,
  0.729960;0.660219;-0.176829;,
  -0.502078;-0.602274;0.620632;,
  -0.000395;-0.582669;0.812709;,
  0.489458;-0.587651;0.644280;,
  0.837726;-0.544549;0.041019;,
  0.669170;-0.362963;-0.648437;,
  -0.097295;-0.314031;-0.944414;,
  -0.666134;-0.389688;-0.635931;,
  -0.828412;-0.559867;0.016797;,
  -0.673260;-0.128636;0.728130;,
  -0.000141;-0.126193;0.992006;,
  0.668232;-0.107658;0.736123;,
  0.997224;-0.071716;0.020035;,
  0.706563;-0.061739;-0.704951;,
  -0.009287;0.037484;-0.999254;,
  -0.704169;-0.094260;-0.703748;,
  -0.993576;-0.112780;0.009351;,
  -0.707108;0.000000;0.707106;,
  -0.000000;0.000000;1.000000;,
  0.707108;0.000000;0.707106;,
  1.000000;0.000000;0.000001;,
  0.707107;0.000000;-0.707107;,
  -0.000000;0.000000;-1.000000;,
  -0.707107;0.000000;-0.707107;,
  -1.000000;0.000000;0.000001;,
  -0.000000;0.000000;1.000000;,
  1.000000;0.000000;0.000001;,
  -1.000000;0.000000;0.000001;,
  0.000000;0.000000;1.000000;,
  1.000000;0.000000;0.000001;,
  0.000827;-0.999405;-0.034473;,
  0.000000;1.000000;0.000000;,
  1.000000;0.000000;0.000000;,
  -0.511452;0.137324;-0.848268;,
  0.448698;-0.372301;-0.812442;,
  0.000000;-0.998983;0.045078;,
  -0.017965;-0.999109;0.038180;,
  0.017965;-0.999109;0.038180;,
  0.027090;-0.999435;0.019923;,
  0.020461;-0.999790;-0.000886;,
  0.000000;-0.999947;-0.010336;,
  -0.020461;-0.999790;-0.000886;,
  -0.027090;-0.999435;0.019923;,
  0.760193;0.649453;0.017840;,
  -0.752570;0.658418;0.011169;,
  -0.548510;0.750191;-0.369256;,
  -0.794216;0.607009;-0.027578;,
  -0.533712;-0.612563;-0.583025;,
  0.000000;-1.000000;-0.000000;;
  108;
  4;0,1,9,8;,
  4;1,2,10,9;,
  4;2,3,11,10;,
  4;3,4,12,11;,
  4;4,5,13,12;,
  4;5,6,14,13;,
  4;6,7,15,14;,
  4;7,0,8,15;,
  4;8,9,17,16;,
  4;9,10,18,17;,
  4;10,11,19,18;,
  4;11,12,20,19;,
  4;12,13,21,20;,
  4;13,14,22,21;,
  4;14,15,23,22;,
  4;15,8,16,23;,
  4;16,17,25,24;,
  4;17,18,26,25;,
  4;18,19,27,26;,
  4;19,20,28,27;,
  4;20,21,29,28;,
  4;21,22,30,29;,
  4;22,23,31,30;,
  4;23,16,24,31;,
  4;24,25,33,32;,
  4;25,26,34,33;,
  4;26,27,35,34;,
  4;27,28,36,35;,
  4;28,29,37,36;,
  4;29,30,38,37;,
  4;30,31,39,38;,
  4;31,24,32,39;,
  3;79,80,40;,
  3;81,79,40;,
  3;82,81,40;,
  3;83,82,40;,
  3;84,83,40;,
  3;85,84,40;,
  3;86,85,40;,
  3;80,86,40;,
  3;32,33,41;,
  3;33,34,41;,
  3;34,35,87;,
  4;35,36,44,87;,
  3;37,42,36;,
  3;36,42,44;,
  3;42,87,44;,
  3;88,89,43;,
  3;89,37,43;,
  3;37,38,43;,
  4;38,39,88,43;,
  3;39,90,88;,
  4;45,46,54,53;,
  4;46,47,55,54;,
  4;47,48,56,55;,
  4;48,49,57,56;,
  3;50,58,78;,
  3;78,58,49;,
  3;58,57,49;,
  3;59,58,51;,
  3;51,58,77;,
  3;58,50,77;,
  4;51,52,60,59;,
  4;52,45,53,60;,
  4;53,54,62,61;,
  4;54,55,63,62;,
  4;55,56,64,63;,
  4;56,57,65,64;,
  4;57,58,66,65;,
  4;58,59,67,66;,
  4;59,60,68,67;,
  4;60,53,61,68;,
  4;61,62,69,61;,
  4;62,63,63,69;,
  4;63,64,70,63;,
  4;64,65,65,70;,
  4;65,66,66,65;,
  4;66,67,67,66;,
  4;67,68,71,67;,
  4;68,61,61,71;,
  4;61,69,72,61;,
  4;69,63,63,72;,
  4;63,70,73,63;,
  4;70,65,65,73;,
  4;65,66,66,65;,
  4;66,67,67,66;,
  4;67,71,71,67;,
  4;71,61,61,71;,
  3;46,45,74;,
  3;47,46,74;,
  3;48,47,74;,
  3;49,48,74;,
  3;49,74,78;,
  3;78,74,50;,
  3;76,76,76;,
  3;74,51,91;,
  3;91,51,50;,
  3;92,92,92;,
  3;52,51,74;,
  3;45,52,74;,
  3;75,75,75;,
  3;75,75,75;,
  3;75,75,75;,
  3;75,75,75;,
  3;75,75,75;,
  3;75,75,75;,
  3;75,75,75;,
  3;75,75,75;;
 }
 MeshTextureCoords {
  134;
  0.221182;0.585260;,
  0.227809;0.585260;,
  0.227809;0.565330;,
  0.221182;0.565330;,
  0.234436;0.585260;,
  0.234436;0.565330;,
  0.241063;0.585260;,
  0.241063;0.565330;,
  0.247690;0.585260;,
  0.247690;0.565330;,
  0.254317;0.585260;,
  0.254317;0.565330;,
  0.260944;0.585260;,
  0.260944;0.565330;,
  0.267570;0.585260;,
  0.267570;0.565330;,
  0.274197;0.585260;,
  0.274197;0.565330;,
  0.227809;0.545399;,
  0.221182;0.545399;,
  0.234436;0.545399;,
  0.241063;0.545399;,
  0.247690;0.545399;,
  0.254317;0.545399;,
  0.260944;0.545399;,
  0.267570;0.545399;,
  0.274197;0.545399;,
  0.227809;0.525468;,
  0.221182;0.525468;,
  0.234436;0.525468;,
  0.241063;0.525468;,
  0.247690;0.525468;,
  0.254317;0.525468;,
  0.260944;0.525468;,
  0.267570;0.525468;,
  0.274197;0.525468;,
  0.227809;0.505538;,
  0.221182;0.505538;,
  0.234436;0.505538;,
  0.241063;0.505538;,
  0.247690;0.505538;,
  0.254317;0.505538;,
  0.260944;0.505538;,
  0.267570;0.505538;,
  0.274197;0.505538;,
  0.247690;0.651529;,
  0.271119;0.641824;,
  0.247690;0.619720;,
  0.224260;0.641824;,
  0.214555;0.618395;,
  0.224260;0.594965;,
  0.247690;0.585260;,
  0.271119;0.594965;,
  0.280824;0.618395;,
  0.271119;0.449173;,
  0.247690;0.439468;,
  0.247690;0.473928;,
  0.224260;0.449173;,
  0.214555;0.472602;,
  0.224260;0.496032;,
  0.228536;0.491998;,
  0.247690;0.505737;,
  0.247690;0.496617;,
  0.267297;0.492426;,
  0.271119;0.496032;,
  0.280824;0.472602;,
  0.199950;0.103478;,
  0.204259;0.103478;,
  0.204259;0.090516;,
  0.199950;0.090516;,
  0.208569;0.103478;,
  0.208569;0.090516;,
  0.212879;0.103478;,
  0.212879;0.090516;,
  0.217189;0.103478;,
  0.217189;0.090516;,
  0.221498;0.103478;,
  0.221498;0.090516;,
  0.219416;0.103478;,
  0.225808;0.090516;,
  0.225808;0.103478;,
  0.223581;0.103478;,
  0.230118;0.103478;,
  0.230118;0.090516;,
  0.234428;0.103478;,
  0.234428;0.090516;,
  0.204259;0.077554;,
  0.199950;0.077554;,
  0.208569;0.077554;,
  0.212879;0.077554;,
  0.217189;0.077554;,
  0.221498;0.077554;,
  0.225808;0.077554;,
  0.230118;0.077554;,
  0.234428;0.077554;,
  0.204259;0.064593;,
  0.199950;0.064593;,
  0.208569;0.064593;,
  0.212879;0.064593;,
  0.217189;0.064593;,
  0.221498;0.064593;,
  0.225808;0.064593;,
  0.230118;0.064593;,
  0.234428;0.064593;,
  0.204259;0.051631;,
  0.199950;0.051631;,
  0.208569;0.051631;,
  0.212879;0.051631;,
  0.217189;0.051631;,
  0.221498;0.051631;,
  0.225808;0.051631;,
  0.230118;0.051631;,
  0.234428;0.051631;,
  0.217189;0.146575;,
  0.232426;0.140264;,
  0.217189;0.125888;,
  0.201951;0.140264;,
  0.195640;0.125026;,
  0.201951;0.109789;,
  0.209825;0.106528;,
  0.217189;0.103478;,
  0.217189;0.114398;,
  0.232426;0.109789;,
  0.224552;0.106528;,
  0.238737;0.125026;,
  0.232426;0.014975;,
  0.217189;0.008663;,
  0.217189;0.031074;,
  0.201951;0.014975;,
  0.195640;0.030212;,
  0.201951;0.045449;,
  0.217189;0.051761;,
  0.232426;0.045449;,
  0.238737;0.030212;;
 }
}
