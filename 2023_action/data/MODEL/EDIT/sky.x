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
 79;
 0.00000;20073.88086;0.00000;,
 0.00000;18545.85352;-7681.94141;,
 5431.95898;18545.85352;-5431.95850;,
 0.00000;20073.88086;0.00000;,
 7681.94141;18545.85352;0.00034;,
 0.00000;20073.88086;0.00000;,
 5431.95850;18545.85352;5431.95850;,
 0.00000;20073.88086;0.00000;,
 -0.00067;18545.85352;7681.94141;,
 0.00000;20073.88086;0.00000;,
 -5431.95898;18545.85352;5431.95850;,
 0.00000;20073.88086;0.00000;,
 -7681.94141;18545.85352;-0.00009;,
 0.00000;20073.88086;0.00000;,
 -5431.95898;18545.85352;-5431.95850;,
 0.00000;20073.88086;0.00000;,
 0.00000;18545.85352;-7681.94141;,
 0.00000;14194.37207;-14194.37207;,
 10036.94043;14194.37207;-10036.94043;,
 14194.37207;14194.37207;0.00062;,
 10036.94043;14194.37207;10036.94043;,
 -0.00124;14194.37207;14194.37207;,
 -10036.94141;14194.37207;10036.94043;,
 -14194.37207;14194.37207;-0.00017;,
 -10036.94141;14194.37207;-10036.94043;,
 0.00000;14194.37207;-14194.37207;,
 0.00000;7681.94092;-18545.85352;,
 13113.89648;7681.94092;-13113.89648;,
 18545.85352;7681.94092;0.00081;,
 13113.89648;7681.94092;13113.89648;,
 -0.00162;7681.94092;18545.85352;,
 -13113.89844;7681.94092;13113.89648;,
 -18545.85352;7681.94092;-0.00022;,
 -13113.89844;7681.94092;-13113.89648;,
 0.00000;7681.94092;-18545.85352;,
 0.00000;-0.00088;-20073.88086;,
 14194.37207;-0.00088;-14194.37207;,
 20073.88086;-0.00088;0.00088;,
 14194.37207;-0.00088;14194.37207;,
 -0.00175;-0.00088;20073.88086;,
 -14194.37891;-0.00088;14194.36621;,
 -20073.88086;-0.00088;-0.00024;,
 -14194.37891;-0.00088;-14194.36621;,
 0.00000;-0.00088;-20073.88086;,
 0.00000;-7681.94141;-18545.85352;,
 13113.89648;-7681.94141;-13113.89648;,
 18545.85352;-7681.94141;0.00081;,
 13113.89648;-7681.94141;13113.89648;,
 -0.00162;-7681.94141;18545.85352;,
 -13113.89844;-7681.94141;13113.89648;,
 -18545.85352;-7681.94141;-0.00022;,
 -13113.89844;-7681.94141;-13113.89648;,
 0.00000;-7681.94141;-18545.85352;,
 0.00000;-14194.37207;-14194.37207;,
 10036.94043;-14194.37207;-10036.94043;,
 14194.37207;-14194.37207;0.00062;,
 10036.94043;-14194.37207;10036.94043;,
 -0.00124;-14194.37207;14194.37207;,
 -10036.94141;-14194.37207;10036.94043;,
 -14194.37207;-14194.37207;-0.00017;,
 -10036.94141;-14194.37207;-10036.94043;,
 0.00000;-14194.37207;-14194.37207;,
 0.00000;-18545.85352;-7681.94141;,
 5431.95898;-18545.85352;-5431.95898;,
 7681.94141;-18545.85352;0.00034;,
 5431.95898;-18545.85352;5431.95898;,
 -0.00067;-18545.85352;7681.94141;,
 -5431.95898;-18545.85352;5431.95850;,
 -7681.94141;-18545.85352;-0.00009;,
 -5431.95898;-18545.85352;-5431.95850;,
 0.00000;-18545.85352;-7681.94141;,
 0.00000;-20073.88086;-0.00000;,
 0.00000;-20073.88086;-0.00000;,
 0.00000;-20073.88086;-0.00000;,
 0.00000;-20073.88086;-0.00000;,
 0.00000;-20073.88086;-0.00000;,
 0.00000;-20073.88086;-0.00000;,
 0.00000;-20073.88086;-0.00000;,
 0.00000;-20073.88086;-0.00000;;
 
 128;
 3;0,1,2;,
 3;3,2,4;,
 3;5,4,6;,
 3;7,6,8;,
 3;9,8,10;,
 3;11,10,12;,
 3;13,12,14;,
 3;15,14,16;,
 4;1,17,18,2;,
 4;2,18,19,4;,
 4;4,19,20,6;,
 4;6,20,21,8;,
 4;8,21,22,10;,
 4;10,22,23,12;,
 4;12,23,24,14;,
 4;14,24,25,16;,
 4;17,26,27,18;,
 4;18,27,28,19;,
 4;19,28,29,20;,
 4;20,29,30,21;,
 4;21,30,31,22;,
 4;22,31,32,23;,
 4;23,32,33,24;,
 4;24,33,34,25;,
 4;26,35,36,27;,
 4;27,36,37,28;,
 4;28,37,38,29;,
 4;29,38,39,30;,
 4;30,39,40,31;,
 4;31,40,41,32;,
 4;32,41,42,33;,
 4;33,42,43,34;,
 4;35,44,45,36;,
 4;36,45,46,37;,
 4;37,46,47,38;,
 4;38,47,48,39;,
 4;39,48,49,40;,
 4;40,49,50,41;,
 4;41,50,51,42;,
 4;42,51,52,43;,
 4;44,53,54,45;,
 4;45,54,55,46;,
 4;46,55,56,47;,
 4;47,56,57,48;,
 4;48,57,58,49;,
 4;49,58,59,50;,
 4;50,59,60,51;,
 4;51,60,61,52;,
 4;53,62,63,54;,
 4;54,63,64,55;,
 4;55,64,65,56;,
 4;56,65,66,57;,
 4;57,66,67,58;,
 4;58,67,68,59;,
 4;59,68,69,60;,
 4;60,69,70,61;,
 3;62,71,63;,
 3;63,72,64;,
 3;64,73,65;,
 3;65,74,66;,
 3;66,75,67;,
 3;67,76,68;,
 3;68,77,69;,
 3;69,78,70;,
 3;1,2,0;,
 3;2,4,3;,
 3;4,6,5;,
 3;6,8,7;,
 3;8,10,9;,
 3;10,12,11;,
 3;12,14,13;,
 3;14,16,15;,
 4;17,18,2,1;,
 4;18,19,4,2;,
 4;19,20,6,4;,
 4;20,21,8,6;,
 4;21,22,10,8;,
 4;22,23,12,10;,
 4;23,24,14,12;,
 4;24,25,16,14;,
 4;26,27,18,17;,
 4;27,28,19,18;,
 4;28,29,20,19;,
 4;29,30,21,20;,
 4;30,31,22,21;,
 4;31,32,23,22;,
 4;32,33,24,23;,
 4;33,34,25,24;,
 4;35,36,27,26;,
 4;36,37,28,27;,
 4;37,38,29,28;,
 4;38,39,30,29;,
 4;39,40,31,30;,
 4;40,41,32,31;,
 4;41,42,33,32;,
 4;42,43,34,33;,
 4;44,45,36,35;,
 4;45,46,37,36;,
 4;46,47,38,37;,
 4;47,48,39,38;,
 4;48,49,40,39;,
 4;49,50,41,40;,
 4;50,51,42,41;,
 4;51,52,43,42;,
 4;53,54,45,44;,
 4;54,55,46,45;,
 4;55,56,47,46;,
 4;56,57,48,47;,
 4;57,58,49,48;,
 4;58,59,50,49;,
 4;59,60,51,50;,
 4;60,61,52,51;,
 4;62,63,54,53;,
 4;63,64,55,54;,
 4;64,65,56,55;,
 4;65,66,57,56;,
 4;66,67,58,57;,
 4;67,68,59,58;,
 4;68,69,60,59;,
 4;69,70,61,60;,
 3;71,63,62;,
 3;72,64,63;,
 3;73,65,64;,
 3;74,66,65;,
 3;75,67,66;,
 3;76,68,67;,
 3;77,69,68;,
 3;78,70,69;;
 
 MeshMaterialList {
  1;
  128;
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
    "data\\TEXTURE\\sky_00351.jpg";
   }
  }
 }
 MeshNormals {
  58;
  0.000000;-1.000000;-0.000000;,
  -0.000000;-0.924735;0.380611;,
  -0.269133;-0.924735;0.269133;,
  -0.380611;-0.924735;-0.000000;,
  -0.269133;-0.924735;-0.269133;,
  0.000000;-0.924735;-0.380611;,
  0.269133;-0.924735;-0.269133;,
  0.380611;-0.924735;0.000000;,
  0.269133;-0.924735;0.269133;,
  -0.000000;-0.709230;0.704977;,
  -0.498494;-0.709230;0.498494;,
  -0.704977;-0.709230;-0.000000;,
  -0.498494;-0.709230;-0.498494;,
  0.000000;-0.709230;-0.704977;,
  0.498494;-0.709230;-0.498494;,
  0.704977;-0.709230;-0.000000;,
  0.498494;-0.709230;0.498494;,
  0.000000;-0.384551;0.923104;,
  -0.652733;-0.384551;0.652733;,
  -0.923104;-0.384551;0.000000;,
  -0.652733;-0.384551;-0.652733;,
  0.000000;-0.384551;-0.923104;,
  0.652733;-0.384551;-0.652733;,
  0.923104;-0.384551;-0.000000;,
  0.652733;-0.384551;0.652733;,
  0.000000;0.000000;1.000000;,
  -0.707107;0.000000;0.707107;,
  -1.000000;0.000000;-0.000000;,
  -0.707107;0.000000;-0.707107;,
  0.000000;0.000000;-1.000000;,
  0.707107;0.000000;-0.707107;,
  1.000000;0.000000;0.000000;,
  0.707107;0.000000;0.707107;,
  0.000000;0.384551;0.923104;,
  -0.652733;0.384551;0.652733;,
  -0.923104;0.384551;0.000000;,
  -0.652733;0.384551;-0.652733;,
  0.000000;0.384551;-0.923104;,
  0.652733;0.384551;-0.652733;,
  0.923104;0.384551;0.000000;,
  0.652733;0.384551;0.652733;,
  -0.000000;0.709230;0.704977;,
  -0.498494;0.709230;0.498494;,
  -0.704977;0.709230;-0.000000;,
  -0.498494;0.709230;-0.498494;,
  0.000000;0.709230;-0.704977;,
  0.498494;0.709230;-0.498494;,
  0.704977;0.709230;0.000000;,
  0.498494;0.709230;0.498494;,
  -0.000000;0.924735;0.380611;,
  -0.269133;0.924735;0.269133;,
  -0.380611;0.924735;-0.000000;,
  -0.269133;0.924735;-0.269133;,
  0.000000;0.924735;-0.380611;,
  0.269133;0.924735;-0.269133;,
  0.380611;0.924735;0.000000;,
  0.269133;0.924735;0.269133;,
  0.000000;1.000000;0.000000;;
  128;
  3;0,1,2;,
  3;0,2,3;,
  3;0,3,4;,
  3;0,4,5;,
  3;0,5,6;,
  3;0,6,7;,
  3;0,7,8;,
  3;0,8,1;,
  4;1,9,10,2;,
  4;2,10,11,3;,
  4;3,11,12,4;,
  4;4,12,13,5;,
  4;5,13,14,6;,
  4;6,14,15,7;,
  4;7,15,16,8;,
  4;8,16,9,1;,
  4;9,17,18,10;,
  4;10,18,19,11;,
  4;11,19,20,12;,
  4;12,20,21,13;,
  4;13,21,22,14;,
  4;14,22,23,15;,
  4;15,23,24,16;,
  4;16,24,17,9;,
  4;17,25,26,18;,
  4;18,26,27,19;,
  4;19,27,28,20;,
  4;20,28,29,21;,
  4;21,29,30,22;,
  4;22,30,31,23;,
  4;23,31,32,24;,
  4;24,32,25,17;,
  4;25,33,34,26;,
  4;26,34,35,27;,
  4;27,35,36,28;,
  4;28,36,37,29;,
  4;29,37,38,30;,
  4;30,38,39,31;,
  4;31,39,40,32;,
  4;32,40,33,25;,
  4;33,41,42,34;,
  4;34,42,43,35;,
  4;35,43,44,36;,
  4;36,44,45,37;,
  4;37,45,46,38;,
  4;38,46,47,39;,
  4;39,47,48,40;,
  4;40,48,41,33;,
  4;41,49,50,42;,
  4;42,50,51,43;,
  4;43,51,52,44;,
  4;44,52,53,45;,
  4;45,53,54,46;,
  4;46,54,55,47;,
  4;47,55,56,48;,
  4;48,56,49,41;,
  3;49,57,50;,
  3;50,57,51;,
  3;51,57,52;,
  3;52,57,53;,
  3;53,57,54;,
  3;54,57,55;,
  3;55,57,56;,
  3;56,57,49;,
  3;1,2,0;,
  3;2,3,0;,
  3;3,4,0;,
  3;4,5,0;,
  3;5,6,0;,
  3;6,7,0;,
  3;7,8,0;,
  3;8,1,0;,
  4;9,10,2,1;,
  4;10,11,3,2;,
  4;11,12,4,3;,
  4;12,13,5,4;,
  4;13,14,6,5;,
  4;14,15,7,6;,
  4;15,16,8,7;,
  4;16,9,1,8;,
  4;17,18,10,9;,
  4;18,19,11,10;,
  4;19,20,12,11;,
  4;20,21,13,12;,
  4;21,22,14,13;,
  4;22,23,15,14;,
  4;23,24,16,15;,
  4;24,17,9,16;,
  4;25,26,18,17;,
  4;26,27,19,18;,
  4;27,28,20,19;,
  4;28,29,21,20;,
  4;29,30,22,21;,
  4;30,31,23,22;,
  4;31,32,24,23;,
  4;32,25,17,24;,
  4;33,34,26,25;,
  4;34,35,27,26;,
  4;35,36,28,27;,
  4;36,37,29,28;,
  4;37,38,30,29;,
  4;38,39,31,30;,
  4;39,40,32,31;,
  4;40,33,25,32;,
  4;41,42,34,33;,
  4;42,43,35,34;,
  4;43,44,36,35;,
  4;44,45,37,36;,
  4;45,46,38,37;,
  4;46,47,39,38;,
  4;47,48,40,39;,
  4;48,41,33,40;,
  4;49,50,42,41;,
  4;50,51,43,42;,
  4;51,52,44,43;,
  4;52,53,45,44;,
  4;53,54,46,45;,
  4;54,55,47,46;,
  4;55,56,48,47;,
  4;56,49,41,48;,
  3;57,50,49;,
  3;57,51,50;,
  3;57,52,51;,
  3;57,53,52;,
  3;57,54,53;,
  3;57,55,54;,
  3;57,56,55;,
  3;57,49,56;;
 }
 MeshTextureCoords {
  79;
  0.062500;0.000000;,
  0.000000;0.125000;,
  0.125000;0.125000;,
  0.187500;0.000000;,
  0.250000;0.125000;,
  0.312500;0.000000;,
  0.375000;0.125000;,
  0.437500;0.000000;,
  0.500000;0.125000;,
  0.562500;0.000000;,
  0.625000;0.125000;,
  0.687500;0.000000;,
  0.750000;0.125000;,
  0.812500;0.000000;,
  0.875000;0.125000;,
  0.937500;0.000000;,
  1.000000;0.125000;,
  0.000000;0.250000;,
  0.125000;0.250000;,
  0.250000;0.250000;,
  0.375000;0.250000;,
  0.500000;0.250000;,
  0.625000;0.250000;,
  0.750000;0.250000;,
  0.875000;0.250000;,
  1.000000;0.250000;,
  0.000000;0.375000;,
  0.125000;0.375000;,
  0.250000;0.375000;,
  0.375000;0.375000;,
  0.500000;0.375000;,
  0.625000;0.375000;,
  0.750000;0.375000;,
  0.875000;0.375000;,
  1.000000;0.375000;,
  0.000000;0.500000;,
  0.125000;0.500000;,
  0.250000;0.500000;,
  0.375000;0.500000;,
  0.500000;0.500000;,
  0.625000;0.500000;,
  0.750000;0.500000;,
  0.875000;0.500000;,
  1.000000;0.500000;,
  0.000000;0.625000;,
  0.125000;0.625000;,
  0.250000;0.625000;,
  0.375000;0.625000;,
  0.500000;0.625000;,
  0.625000;0.625000;,
  0.750000;0.625000;,
  0.875000;0.625000;,
  1.000000;0.625000;,
  0.000000;0.750000;,
  0.125000;0.750000;,
  0.250000;0.750000;,
  0.375000;0.750000;,
  0.500000;0.750000;,
  0.625000;0.750000;,
  0.750000;0.750000;,
  0.875000;0.750000;,
  1.000000;0.750000;,
  0.000000;0.875000;,
  0.125000;0.875000;,
  0.250000;0.875000;,
  0.375000;0.875000;,
  0.500000;0.875000;,
  0.625000;0.875000;,
  0.750000;0.875000;,
  0.875000;0.875000;,
  1.000000;0.875000;,
  0.062500;1.000000;,
  0.187500;1.000000;,
  0.312500;1.000000;,
  0.437500;1.000000;,
  0.562500;1.000000;,
  0.687500;1.000000;,
  0.812500;1.000000;,
  0.937500;1.000000;;
 }
}
