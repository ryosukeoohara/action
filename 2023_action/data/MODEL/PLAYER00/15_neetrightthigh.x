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
 63;
 -3.28775;-23.29943;2.51483;,
 0.07105;-23.30506;3.68577;,
 0.06965;-22.07073;4.98853;,
 -3.79988;-22.06181;3.47054;,
 3.42913;-23.27702;2.51306;,
 3.93349;-22.03601;3.46850;,
 4.40224;-23.23101;-0.46315;,
 5.43532;-21.97556;-0.38959;,
 3.42709;-23.19142;-3.44379;,
 3.93081;-21.92505;-4.25328;,
 0.07127;-23.39945;-4.71273;,
 0.06628;-21.91513;-5.83959;,
 -3.28943;-23.21382;-3.44202;,
 -3.80202;-21.95084;-4.25124;,
 -4.26273;-23.25991;-0.46087;,
 -5.30412;-22.01139;-0.38676;,
 -3.28775;-23.29943;2.51483;,
 -3.79988;-22.06181;3.47054;,
 0.06073;-20.09595;5.14082;,
 -3.86311;-20.08569;3.51692;,
 3.98355;-20.05951;3.51485;,
 5.60743;-19.99772;-0.40852;,
 3.98111;-19.94676;-4.33104;,
 0.05727;-19.93650;-5.95494;,
 -3.86555;-19.97294;-4.32897;,
 -5.48943;-20.03473;-0.40560;,
 -3.86311;-20.08569;3.51692;,
 0.02226;-11.28717;5.30675;,
 -3.90158;-11.27691;3.68285;,
 3.94508;-11.25074;3.68078;,
 5.56896;-11.18894;-0.24260;,
 3.94264;-11.13799;-4.16511;,
 0.01844;-11.11119;-6.93968;,
 -3.90402;-11.16416;-4.16304;,
 -5.52790;-11.22596;-0.23967;,
 -3.90158;-11.27691;3.68285;,
 -0.00019;-4.58922;4.88065;,
 -3.92387;-4.58646;3.77900;,
 3.92279;-4.56029;3.77693;,
 5.54666;-4.49849;-0.14644;,
 3.92035;-4.44754;-4.06896;,
 -0.00385;-4.42074;-6.84353;,
 -3.92631;-4.47371;-4.06689;,
 -5.55019;-4.53551;-0.14352;,
 -3.92387;-4.58646;3.77900;,
 0.07105;-23.30506;3.68577;,
 -3.28775;-23.29943;2.51483;,
 0.07350;-24.36877;-0.47815;,
 3.42913;-23.27702;2.51306;,
 4.40224;-23.23101;-0.46315;,
 3.42709;-23.19142;-3.44379;,
 0.07127;-23.39945;-4.71273;,
 -3.28943;-23.21382;-3.44202;,
 -4.26273;-23.25991;-0.46087;,
 -3.92387;-4.58646;3.77900;,
 -0.00019;-4.58922;4.88065;,
 -0.01745;0.19152;-0.07731;,
 3.92279;-4.56029;3.77693;,
 5.54666;-4.49849;-0.14644;,
 3.92035;-4.44754;-4.06896;,
 -0.00385;-4.42074;-6.84353;,
 -3.92631;-4.47371;-4.06689;,
 -5.55019;-4.53551;-0.14352;;
 
 48;
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
 3;58,59,56;,
 3;59,60,56;,
 3;60,61,56;,
 3;61,62,56;,
 3;62,54,56;;
 
 MeshMaterialList {
  6;
  48;
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2;;
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data\\TEXTURE\\neet.png";
   }
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data\\TEXTURE\\neett.jpg";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data\\TEXTURE\\neett.png";
   }
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data\\TEXTURE\\UV_Grid.png";
   }
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "data\\TEXTURE\\UV_Grid.png";
   }
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  44;
  -0.365207;-0.865404;0.343074;,
  0.003046;-0.868930;0.494926;,
  0.371157;-0.862979;0.342798;,
  0.553805;-0.832544;-0.013067;,
  0.404335;-0.837472;-0.367633;,
  0.002814;-0.848313;-0.529487;,
  -0.398820;-0.840166;-0.367510;,
  -0.548244;-0.836221;-0.012777;,
  -0.658984;-0.393788;0.640836;,
  0.001686;-0.411522;0.911398;,
  0.662057;-0.389227;0.640455;,
  0.936928;-0.349468;-0.006129;,
  0.670677;-0.352587;-0.652591;,
  0.001093;-0.356310;-0.934367;,
  -0.668515;-0.357184;-0.652310;,
  -0.934579;-0.355712;-0.005636;,
  -0.706735;-0.039170;0.706393;,
  0.000441;-0.037438;0.999299;,
  0.707400;-0.033481;0.706020;,
  0.999577;-0.029083;-0.000565;,
  0.727468;-0.035948;-0.685200;,
  -0.000035;-0.048576;-0.998820;,
  -0.727506;-0.041703;-0.684833;,
  -0.999323;-0.036784;-0.000054;,
  -0.696425;-0.004770;0.717614;,
  0.000255;0.002719;0.999996;,
  0.696813;0.000615;0.717253;,
  0.999992;0.003854;-0.000256;,
  0.763679;-0.000361;-0.645596;,
  -0.000206;-0.014916;-0.999889;,
  -0.763992;-0.006221;-0.645196;,
  -0.999993;-0.003854;0.000255;,
  -0.608062;0.426078;0.669864;,
  -0.001124;0.409196;0.912446;,
  0.605560;0.430126;0.669544;,
  0.901682;0.432358;0.005933;,
  0.707549;0.433697;-0.557926;,
  0.230233;0.621679;-0.748671;,
  -0.710720;0.428966;-0.557553;,
  -0.904543;0.426333;0.006408;,
  0.003351;-0.999994;-0.000532;,
  0.394858;0.894222;0.210841;,
  -0.577833;0.009803;-0.816096;,
  -0.581294;0.794016;-0.177865;;
  48;
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
  4;29,30,38,42;,
  4;30,31,39,38;,
  4;31,24,32,39;,
  3;1,0,40;,
  3;2,1,40;,
  3;3,2,40;,
  3;4,3,40;,
  3;5,4,40;,
  3;6,5,40;,
  3;7,6,40;,
  3;0,7,40;,
  3;32,33,41;,
  3;33,34,41;,
  3;34,35,41;,
  3;35,36,41;,
  3;36,37,41;,
  3;37,38,43;,
  3;38,39,43;,
  3;39,32,43;;
 }
 MeshTextureCoords {
  63;
  0.795987;0.616579;,
  0.804035;0.616579;,
  0.804035;0.592375;,
  0.795987;0.592375;,
  0.812083;0.616579;,
  0.812083;0.592375;,
  0.820130;0.616579;,
  0.820130;0.592375;,
  0.828178;0.616579;,
  0.828178;0.592375;,
  0.836226;0.616579;,
  0.836226;0.592375;,
  0.844274;0.616579;,
  0.844274;0.592375;,
  0.852322;0.616579;,
  0.852322;0.592375;,
  0.860370;0.616579;,
  0.860370;0.592375;,
  0.804035;0.568171;,
  0.795987;0.568171;,
  0.812083;0.568171;,
  0.820130;0.568171;,
  0.828178;0.568171;,
  0.836226;0.568171;,
  0.844274;0.568171;,
  0.852322;0.568171;,
  0.860370;0.568171;,
  0.804035;0.543967;,
  0.795987;0.543967;,
  0.812083;0.543967;,
  0.820130;0.543967;,
  0.828178;0.543967;,
  0.836226;0.543967;,
  0.844274;0.543967;,
  0.852322;0.543967;,
  0.860370;0.543967;,
  0.804035;0.519763;,
  0.795987;0.519763;,
  0.812083;0.519763;,
  0.820130;0.519763;,
  0.828178;0.519763;,
  0.836226;0.519763;,
  0.844274;0.519763;,
  0.852322;0.519763;,
  0.860370;0.519763;,
  0.828178;0.697058;,
  0.856632;0.685272;,
  0.828178;0.658428;,
  0.799725;0.685272;,
  0.787939;0.656818;,
  0.799725;0.628365;,
  0.828178;0.616579;,
  0.856632;0.628365;,
  0.868418;0.656818;,
  0.856632;0.451312;,
  0.828178;0.439526;,
  0.828178;0.481375;,
  0.799725;0.451312;,
  0.787939;0.479765;,
  0.799725;0.508219;,
  0.828178;0.520005;,
  0.856632;0.508219;,
  0.868418;0.479765;;
 }
}
