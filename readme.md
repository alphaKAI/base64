簡易Base64エンコーダ/デコーダ
==================


なにこれ
------------------
簡易base64エンコーダ/デコーダです  
  
  
使用ライブラリ/ライセンス
------------------
Sugarless<http://ishibasystems.ikaduchi.com/downloads/d_8/main.htmlSugarless>12 著作者 石橋祥太 / 藤代晴嵐 LICENSE: NYSL Version 0.9982  
Sugarless12はファイルを必要最低限にしてあります  
readme.txtがSugarless12フォルダにreadme.txtが入っていますのでそちらもお読みください  
簡易base64エンコーダ/デコーダ 著作者 α改 LICENSE GPLv3  
GPLv3については同梱のLICENSEフォルダのLICENSE(原文)/LICENSE_ja(日本語訳)をご覧ください  
  
  
機能
-----------------
STRING ENCODE/DECODE -> 文字列のエンコード/デコード  
FILE ENCODE/DECODE -> ファイルのエンコード/デコード  
  
  
使い方
-----------------
まずコンパイルします(コマンド間違ってたらごめんなさい)　　
　　
　　  
Windows:  
    >cd sugarless12  
    >compiler cl /c *.c  
    >lib *.obj  
    >cd ../
    >cl *.c sugarless12/*.lib
  
Linux:  
    $ cd sugarless12  
    $ gcc -c *.c  
    $ ar rv sugarless12.a *.o  
    $ cd ../  
    $ gcc -o base64 *.c sugarless12/*.a  
  

  
使い方  
    COMMAND : base64 [Option] [String] [OUTPUTFILENAME]  
    [Option]:  
    -e  :  文字列のエンコード  
    -d  :  文字列のデコード  
    -fe  :  ファイルのエンコード  
    -fd  :  ファイルのデコード  
    ファイルのエンデコのときのみOUTPUTFILENAMEはつかえます  
    --help  :  使い方表示(現在の出力と同じです)  
    -v  :  バージョン情報  
　　
  
作者
-------------------
α改 @alpha_kai_NET<https://twitter.com/alpha_kai_NET>  
  
  
WEB SITE
-------------------

個人ブログ <http://blog.alpha-kai-net.info>  
HP <http://alpha-kai-net.info>  
Twitter <http://twitter.com/alpha_kai_net>  
Github <https://github.com/alphaKAI>  
Mail to <alpha.kai.net@alpha-kai-net.info>




COPYRIGHT (c) α改 2012-2013 @alpha_kai_NET http://alha-kai-net.info
