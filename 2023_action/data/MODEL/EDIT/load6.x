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
 42;
 -361.69995;0.27775;199.95383;,
 -361.69995;0.27775;2031.08423;,
 -361.69995;31.32170;2031.08423;,
 -361.69995;31.32170;199.95383;,
 -330.22089;31.32170;2031.08411;,
 -330.22083;31.32170;199.95389;,
 -330.22089;0.27775;2031.08411;,
 -330.22083;0.27775;199.95389;,
 -361.69995;0.27775;2031.08423;,
 -361.69995;0.27775;199.95383;,
 -330.22089;0.27775;2031.08411;,
 -330.22089;31.32170;2031.08411;,
 -330.22083;0.27775;199.95389;,
 -330.22083;31.32170;199.95389;,
 -341.97180;0.26140;-1834.05627;,
 -341.97086;0.26140;2031.44128;,
 -341.97086;16.68390;2031.44128;,
 -341.97180;16.68390;-1834.05627;,
 111.48283;16.68390;2031.44348;,
 111.48161;16.68390;-1834.05688;,
 111.48283;0.26140;2031.44348;,
 111.48161;0.26140;-1834.05688;,
 -341.97086;0.26140;2031.44128;,
 -341.97180;0.26140;-1834.05627;,
 111.48283;0.26140;2031.44348;,
 111.48283;16.68390;2031.44348;,
 111.48161;0.26140;-1834.05688;,
 111.48161;16.68390;-1834.05688;,
 -361.70007;0.27775;-1834.05579;,
 -361.69995;0.27775;-164.03569;,
 -361.69995;31.32170;-164.03569;,
 -361.70007;31.32170;-1834.05579;,
 -330.22089;31.32170;-164.03569;,
 -330.22076;31.32170;-1834.05579;,
 -330.22089;0.27775;-164.03569;,
 -330.22076;0.27775;-1834.05579;,
 -361.69995;0.27775;-164.03569;,
 -361.70007;0.27775;-1834.05579;,
 -330.22089;0.27775;-164.03569;,
 -330.22089;31.32170;-164.03569;,
 -330.22076;0.27775;-1834.05579;,
 -330.22076;31.32170;-1834.05579;;
 
 18;
 4;0,1,2,3;,
 4;3,2,4,5;,
 4;5,4,6,7;,
 4;7,6,8,9;,
 4;1,10,11,2;,
 4;12,0,3,13;,
 4;14,15,16,17;,
 4;17,16,18,19;,
 4;19,18,20,21;,
 4;21,20,22,23;,
 4;15,24,25,16;,
 4;26,14,17,27;,
 4;28,29,30,31;,
 4;31,30,32,33;,
 4;33,32,34,35;,
 4;35,34,36,37;,
 4;29,38,39,30;,
 4;40,28,31,41;;
 
 MeshMaterialList {
  2;
  18;
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
   0.056000;0.056000;0.056000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  14;
  -1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  1.000000;0.000000;0.000000;,
  -1.000000;0.000000;0.000000;,
  1.000000;0.000000;-0.000000;,
  -1.000000;0.000000;0.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.000004;0.000000;1.000000;,
  0.000002;0.000000;-1.000000;,
  -0.000005;0.000000;1.000000;,
  -0.000001;0.000000;-1.000000;,
  0.000000;0.000000;1.000000;,
  0.000000;0.000000;-1.000000;;
  18;
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;7,7,7,7;,
  4;8,8,8,8;,
  4;9,9,9,9;,
  4;3,3,3,3;,
  4;1,1,1,1;,
  4;4,4,4,4;,
  4;7,7,7,7;,
  4;10,10,10,10;,
  4;11,11,11,11;,
  4;5,5,5,5;,
  4;1,1,1,1;,
  4;6,6,6,6;,
  4;7,7,7,7;,
  4;12,12,12,12;,
  4;13,13,13,13;;
 }
 MeshTextureCoords {
  42;
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