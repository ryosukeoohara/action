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
 28;
 1641.51917;0.26140;-209.67818;,
 -1641.51917;0.26140;-209.67818;,
 -1641.51917;16.68390;-209.67818;,
 1641.51917;16.68390;-209.67818;,
 -1641.51917;16.68390;228.75349;,
 1641.51917;16.68390;228.75349;,
 -1641.51917;0.26140;228.75349;,
 1641.51917;0.26140;228.75349;,
 -1641.51917;0.26140;-209.67818;,
 1641.51917;0.26140;-209.67818;,
 -1641.51917;0.26140;228.75349;,
 -1641.51917;16.68390;228.75349;,
 1641.51917;0.26140;228.75349;,
 1641.51917;16.68390;228.75349;,
 1641.51917;0.27775;-228.75349;,
 -1641.51917;0.27775;-228.75349;,
 -1641.51917;31.32170;-228.75349;,
 1641.51917;31.32170;-228.75349;,
 -1641.51917;31.32170;-198.31696;,
 1641.51917;31.32170;-198.31696;,
 -1641.51917;0.27775;-198.31696;,
 1641.51917;0.27775;-198.31696;,
 -1641.51917;0.27775;-228.75349;,
 1641.51917;0.27775;-228.75349;,
 -1641.51917;0.27775;-198.31696;,
 -1641.51917;31.32170;-198.31696;,
 1641.51917;0.27775;-198.31696;,
 1641.51917;31.32170;-198.31696;;
 
 12;
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
 4;26,14,17,27;;
 
 MeshMaterialList {
  2;
  12;
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
  6;
  0.000000;0.000000;-1.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  0.000000;-1.000000;0.000000;,
  -1.000000;0.000000;0.000000;,
  1.000000;0.000000;0.000000;;
  12;
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;3,3,3,3;,
  4;4,4,4,4;,
  4;5,5,5,5;,
  4;0,0,0,0;,
  4;1,1,1,1;,
  4;2,2,2,2;,
  4;3,3,3,3;,
  4;4,4,4,4;,
  4;5,5,5,5;;
 }
 MeshTextureCoords {
  28;
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
