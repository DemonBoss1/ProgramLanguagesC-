﻿#include "main.h"

//stack<char>* stackWhite(ifstream fin) {
//
//}

void testTransfer();


int main()
{
  /*  setlocale(LC_ALL, "Rus");
    string str1 = "Это изменяет размер вектора. Если новый размер меньше старого, то элементы ближе к концу стираются. Если новый размер больше, то ближе к концу добавляется какое-то значение по умолчанию. Чтобы добавить определенную ценность, используйте функцию resize ( с двумя аргументами. Следующий фрагмент кода иллюстрирует использование этих двух функций:";
    SetConsoleCP(1251);
    getline(cin, str1);
    SetConsoleCP(866);
    createHistogram(str1);*/
    string str2="(͡° ͜ʖ ͡°)        (͡°╭͜ʖ╮͡°)        (͡ʘ ͜ʖ ͡ʘ)        (✷‿✷)        \\_(ツ)_ / ¯        (͡⊙ ͜ʖ ͡⊙)﻿        (V)(; , ;)(V)        (> ^ .^) >        (^ *o*) ^        ▄︻̷̿┻̿═━一        ¯|\_(ツ)_ / ¯        [✖‿✖]﻿        ʕ•ᴥ•ʔ        (ง ͠° ͟ل͜ ͡°)ง        ༼ つ ◕_◕ ༽つ        (づ｡◕‿‿◕｡)づ        (͡°╭͜ʖ╮͡°)        [̲̅$̲̅(̲̅5̲̅)̲̅$̲̅]    [̲̅$̲̅(̲̅ ͡° ͜ʖ ͡°̲̅)̲̅$̲̅]    (ﾉ◕ヮ◕)ﾉ * :･ﾟ✧ ✧ﾟ･ : *ヽ(◕ヮ◕ヽ)        (ಠ_ಠ)        (ಥ﹏ಥ)        (づ￣ ³￣)づ        | (• ◡•) |        (❍ᴥ❍ʋ)        (ノಠ益ಠ)ノ彡┻━┻        ﴾͡๏̯͡๏﴿        ٩(͡๏̯͡๏)۶        ಠ_ಠ        (☞ﾟヮﾟ)☞ ☜(ﾟヮﾟ☜)        (╯°□°)╯︵ ʞooqǝɔɐɟ        (╯°□°)╯︵ ɐǝʇ        (͡ᵔ ͜ʖ ͡ᵔ)        (☞ﾟヮﾟ)☞        ヾ(⌐■_■)ノ♪        ヽ༼ຈل͜ຈ༽ﾉ        ༼ つ ಥ_ಥ ༽つ        (ง'̀-'́)ง        (•_•)> ⌐■ - ■(⌐■_■)(╯°□°）╯︵ ┻━┻    ᕦ(ò_óˇ)ᕤ    (ﾉ◕ヮ◕)ﾉ * :･ﾟ✧    ┻━┻ ︵ヽ(`Д´)ﾉ︵ ┻━┻    (☞ﾟ∀ﾟ)☞    (._.) (l : ) (. - .) (:l) (._.)    ┬┴┬┴┤(･_├┬┴┬┴        ┬┴┬┴┤ ͜ʖ ͡°) ├┬┴┬┴    ᕙ(⇀‸↼‶)ᕗ    (~˘▾˘)~(◕‿◕)    (｡◕‿‿◕｡)    (｡◕‿◕｡)    ~(˘▾˘~)    (°ロ°)☝    ⌐╦╦═─    (☞ຈل͜ຈ)☞    (ง°ل͜°)ง    ┌(ಠ_ಠ)┘    ◉_◉    (╯°□°）╯︵(.o.)        ┬──┬ ノ(゜ - ゜ノ)        ☜(˚▽˚)☞        (─‿‿─)        ლ(´ڡ`ლ)        (ಥ_ಥ)        ᄽὁȍ ̪ őὀᄿ        \\ (•◡•) /        (° ͡ ͜ ͡ʖ ͡ °)        ☜(⌒▽⌒)☞        + 1 ☜(⌒▽⌒)☞ + 1        ｡◕‿‿◕｡        ╚(ಠ_ಠ) = ┐        (ಠ‿ಠ)        (ʘᗩʘ')            (✿´‿`)                ಥ_ಥ                (ღ˘⌣˘ღ)                (；一_一)                ¯\\(°_o) / ¯                (¬‿¬)                ͠° ͟ل͜ ͡°                (> ლ)                (｡◕‿◕｡)                ┬─┬ノ(º _ ºノ)                凸(-_ - )凸                ̿ ̿ ̿'̿'\\̵͇̿̿\\з = (•_•) = ε / ̵͇̿̿ / '̿'̿ ̿                ̿̿ ̿̿ ̿̿ ̿'̿'\\̵͇̿̿\\з = (▀ ͜͞ʖ▀) = ε / ̵͇̿̿ / '̿'̿ ̿ ̿̿ ̿̿ ̿̿                ̿'̿'\\̵͇̿̿\\з = (͠° ͟ʖ ͡°) = ε / ̵͇̿̿ / '̿̿ ̿ ̿ ̿ ̿ ̿                •_•)            (•_•) > ⌐■ - ■            (⌐■_■)            o()xxxx[{: >            O == = | _________________ /            ¦̵̱ ̵̱ ̵̱ ̵̱ ̵̱(̢ ̡͇̅└͇̅┘͇̅(▤8כ−◦                ༼ つ ಥ_ಥ ༽つ                | (• ◡•) |                (❍ᴥ❍ʋ)                t(-. - )t                (☞ﾟヮﾟ)☞                (; ´༎ຶД༎ຶ`)                    <: [] = ¤༼ຈل͜ຈ༽ﾉ                    (͡° ͜ʖ ͡°) ▄︻̷̿┻̿═━一 ʕ•ᴥ•ʔ                    ლ(ಠ益ಠლ)                    (⌐■_■)>¸, ø¤º°`°º¤ø, ¸¸                    (͝סּ ͜ʖ͡סּ)                    (x_x)@~(-_ - Q)                    (ﾉ◕ヮ◕)ﾉ * :･ﾟ✧                    (ﾉ◕ヮ◕)ﾉ * : ･ﾟ✧                    (͡° ͜ʖ ͡°) ▄︻̷̿┻̿═━一(ʘᗩʘ')                        ζ༼Ɵ͆ل͜Ɵ͆༽ᶘ                        ლ(ಠ‿ಠლ)                        ================================                        :-D                        XD                        : P                        %*}    :')        < : 0)        > : )                B - )                :-)            < 3 S        = (            > :E> :-(    = |    ~:-(>        ; -(‘        (:-&            : -@            : -r            : -*            : -**            ;;)           ;)        : -*)    : -«   : 3    : -&    (:-{)    } : -)            : -K            ================================            ➳ ღ ❥ ♥ ❢ ❦ ❧ ☜♡☞            ================================            ← ↑ → ↓ ↔ ↕ ⇐ ⇒           ================================            < ^ O^>            (^ .^) /            *^O ^ *            \\, / (^ _^)\\, /            !d ^ _ ^ b            \\(^ O^) /            (/ .\\)            (-_ - )            (> _ < )            (-_\\\\\\)            (@_@)            (~.~)            ) - 00 - (                (o_O)                (u_u)                (= _ = )                * o *                -^ o ^ -                (> ^ _^) > < (^ _ ^ < )                (o)_(o)                ================================                ッ                ヅ                ツ                ゾ                シ                ジ                ｯ                ﾂ                ｼ                ================================                ͡๏̯͡๏ ͡๏̮͡๏(̾●̮̮̃̾•̃̾) (●̮̮̃●̃) (-̮̮̃ - ̃) (-̮̮̃•̃) †(•̪●)†                (● * ∩_∩ * ●) (*^—^*) (-'_' - ) (¬_¬) (◡‿◡✿) (◕‿◕✿) (✖╭╮✖) (≧◡≦) (✿◠‿◠)                (◑‿◐)(◕‿ - ) ✖‿✖ ಠ_ಠ 凸(¬‿¬)凸 ┌∩┐(◣_◢)┌∩┐(⊙▂⊙) (≧ω≦) o(≧o≦)o(⋋▂⋌) (•̪●) (॓_॔)                (╯ಊ╰)(─‿‿─)(⊙_◎)(╯︵╰, ) (｡◕‿◕｡) (｡❤‿❤｡) (✿ ♥‿♥) (｡♥‿♥｡) (～o❤‿❤～o)                ============================== =                Радость:    (-‿‿ - )        < (￣︶￣) >        (*⌒―⌒*)        ヽ(・∀・)ﾉ        (´｡• ω •｡`)            (＠＾－＾)            (o ^ ▽ ^ o)            ヽ(*・ω・)ﾉ            (^ 人^)            (o´▽`o)                (*´▽`*)                ｡ﾟ(ﾟ ^ ∀ ^ ﾟ)ﾟ｡                (´ω｀)                (≧◡≦)                (＾▽＾)                (⌒ω⌒)                (⌒▽⌒)☆                ∑d(ﾟ∀ﾟd)                ╰(▔∀▔)╯                (─‿‿─)                (*^‿^*)                ヽ(o ^ ― ^ o)ﾉ                (✯◡✯)                (◕‿◕)                (*≧ω≦*)                (((o(*ﾟ▽ﾟ*)o)))                (⌒‿⌒)               ＼(≧▽≦)／                ⌒(o＾▽＾o)ノ                (*ﾟ▽ﾟ*)                ヽ(*⌒▽⌒*)ﾉ                (´｡• ᵕ •｡`)                    (´ ▽ `)                        (￣▽￣)                        ╰(*´︶`*)╯                        ヽ(> ∀ < ☆)ノ                        o(≧▽≦)o                        (☆ω☆)                        (っ˘ω˘ς)                        ＼(￣▽￣)／                        (*¯︶¯*)                        ＼(＾▽＾)／                        ٩(◕‿◕)۶                        (o˘◡˘o)                        Любовь и поцелуи :    (ﾉ´з｀)ノ я тебя обожаю    (♡μ_μ) я без тебя не могу    (*^^*)♡    (♡ - _ - ♡) интроверты тоже умеют любить    (￣ε￣＠) поцелуй меня        ヽ(♡‿♡)ノ иди ко мне, любовь моя        ♡(─‿‿─)♡        (´｡• ᵕ •｡`) ♡ я втюрился        (｡・//ε//・｡) губки бантиком        (´ω｀♡)            (◡‿◡ ♡) я тебя сильно люблю            (◕‿◕)♡            (ღ˘⌣˘ღ) мне с тобой так хорошо           (♡ﾟ▽ﾟ♡) влюбленность            (´• ω •`) ♡            (´ε｀)                ♡(´｡• ω •｡`) ♡ о боже, я опять влюбился по уши                (´ ▽ `).｡ｏ♡ мое сердце принадлежит тебе                    ╰(*´︶`*)╯♡ меня переполняет любовь                    (*˘︶˘*).｡.:*♡ в любви и в полнй гармонии                    (♡˙︶˙♡)                    ♡＼(￣▽￣)／♡ люблю всех!                    (≧◡≦)ты мне очень нравишься                    ♡(⌒▽⌒)♡                    (*¯ ³¯*)♡                 (˘⌣˘)♡(˘⌣˘) мы любим друг - друга                   (/ ^ -^ (^^*) / ♡ целуемся и обнимаемся                        Смущение : (⌒_⌒;) (o ^ ^o)        (*/ ω＼)        (*/ 。＼)        (*/ _＼)        (*ﾉωﾉ)        (o - _ - o)        (*μ_μ)        (◡‿◡*)        (ᵔ.ᵔ)        (*ﾉ∀`*)        (//▽//)            (//ω//)                (ノ * ﾟ▽ﾟ*)                (*^.^*)                (*ﾉ▽ﾉ)                (￣▽￣*)ゞ                (⁄ ⁄•⁄ω⁄•⁄ ⁄)                (*/ ▽＼*)                Сочувствие:   (ノ_ < 。)ヾ(´▽｀) ｡･ﾟ･(ﾉД`)ヽ(￣ω￣) ρ(-ω - 、)ヾ(￣ω￣;)        ヽ(￣ω￣(。。)ゝ(*´I｀)ﾉﾟ(ﾉД｀ﾟ)ﾟ｡ ヽ(~_~(・_・)ゝ(ﾉ＿；)ヾ(´∀｀) (；ω；)ヾ(´∀｀*) (*´ー)ﾉ(ノд`)(´ - ω - `(_ _) (っ´ω｀)ﾉ(╥ω╥) (ｏ・_・)ノ»(ノ_ < 、)            Недовольство:    (＃＞＜)(；⌣̀_⌣́)☆ｏ(＞＜；)○(￣ ￣|||)        (；￣Д￣)(￣□￣」)(＃￣0￣)(＃￣ω￣)(￢_￢;) (＞ｍ＜) (」゜ロ゜)」(〃＞＿＜; 〃)(＾＾＃) (︶︹︺) (￣ヘ￣) < (￣ ﹌ ￣) > (￣︿￣)(＞﹏＜)(--_--) 凸(￣ヘ￣)ヾ(￣O￣)ツ(⇀‸↼‶) o(> < )o        Злость :    (＃`Д´) (｀皿´＃) (｀ω´) ヽ(`д´*)ノ    (・｀ω´・) (｀ー´)ヽ(｀⌒´メ)ノ 凸(｀△´＃)(｀ε´) ψ(｀∇´)ψ ヾ(｀ヘ´)ﾉﾞ ヽ(‵﹏′)ノ(ﾒ｀ﾛ´) (╬｀益´) ┌∩┐(◣_◢)┌∩┐ 凸(｀ﾛ´)凸Σ(▼□▼メ) (°ㅂ°╬) ψ(▼へ▼メ)～→(ノ°益°)ノ(҂ `з´) (‡▼益▼) (҂｀ﾛ´)凸((╬◣﹏◢))٩(╬ʘ益ʘ╬)۶(╬ Ò﹏Ó) ＼＼٩(๑`^´๑)۶／／        Печаль :    (ノ_ < 。) (*-_ - ) (´ - ω - ｀).･ﾟﾟ･(／ω＼)･ﾟﾟ･.        (μ_μ)(ﾉД`) (-ω - 、) 。゜゜(´Ｏ｀)°゜。o(TヘTo) (；ω；) (｡╯3╰｡) ｡･ﾟﾟ * (> д < ) * ﾟﾟ･｡(ﾟ，_ゝ｀) (个_个) (╯︵╰, ) ｡･ﾟ(ﾟ > < ﾟ)ﾟ･｡(╥ω╥) (╯_╰) (╥_╥).｡･ﾟﾟ･(＞_＜)･ﾟﾟ･｡.(／ˍ・、)(ノ_ < 、) (╥﹏╥) ｡ﾟ(｡ﾉωヽ｡)ﾟ｡(つω`*) (｡T ω T｡) (ﾉω･､) ･ﾟ･(｡ > ω < ｡)･ﾟ･(T_T) (> _ < ) (Ｔ▽Ｔ) ｡ﾟ･(> ﹏ < ) ･ﾟ｡o(〒﹏〒)o            Страх :    (ノωヽ)(／。＼)(ﾉ_ヽ).・ヾ(。＞＜)シ    (″ロ゛) (;;; *_*) (・人・) ＼(〇_ｏ)／(/ ω＼) (/ _＼) 〜(＞＜)〜 Σ(°△°|||)︴(((＞＜))) { { (> _ < ) } } ＼(º □ º l | l) / 〣(ºΔº)〣        Безразличие :    ヽ(ー_ー)ノ ヽ(´ー｀)┌ ┐(‘～`)┌ ヽ(￣д￣)ノ        ┐(￣ヘ￣)┌ ヽ(￣～￣　)ノ ╮(￣_￣)╭ ヽ(ˇヘˇ)ノ┐(￣～￣)┌ ┐(︶▽︶)┌ ╮(￣～￣)╭ ¯＼_(ツ)_ / ¯┐(´д｀)┌ ╮(︶︿︶)╭ ┐(￣∀￣)┌ ┐(˘ ､ ˘)┌        Замешательство :    (￣ω￣;) σ(￣、￣〃) (￣～￣;) (-_ - ;)・・・┐('～`;)┌ (・_・ヾ (〃￣ω￣〃ゞ ┐(￣ヘ￣;)┌(・_・;) (￣_￣)・・・ ╮(￣ω￣;)╭ (￣.￣;)(＠_＠) (・・;)ゞ Σ(￣。￣ﾉ) (・・) ?(•ิ_•ิ)? (◎ ◎)ゞ (ーー;)        Сомнение:    (￢_￢)(→_→)(￢ ￢) (￢‿￢)(¬_¬) (←_←) (¬ ¬) (¬‿¬)(↼_↼) (⇀_⇀)        Удивление :        w(ﾟｏﾟ)w ヽ(ﾟ〇ﾟ)ﾉ Σ(O_O) Σ(ﾟロﾟ)        (⊙_⊙)(o_O)(O_O;) (O.O)(ﾟロﾟ) !(o_O)!(□_□)Σ(□_□)∑(O_O;)        Приветствие        (*・ω・)ﾉ(￣▽￣)ノ(ﾟ▽ﾟ) / (*´∀｀)ﾉ        (^ -^*) / (＠´ー`)ﾉﾞ(´• ω •`)ﾉ(ﾟ∀ﾟ)ﾉﾞヾ(*'▽'*) ＼(⌒▽⌒) ヾ(☆▽☆) (´ ▽ `)ﾉ(^ ０^)ノ ~ヾ(・ω・) (・∀・)ノ ヾ(^ ω^*)(*ﾟｰﾟ)ﾉ(・_・)ノ(o´ω`o)ﾉ ヾ(☆'∀'☆)(￣ω￣) / (´ω｀)ノﾞ(⌒ω⌒)ﾉ(o ^ ^o) / (≧▽≦) / (✧∀✧) / (o´▽`o)ﾉ(￣▽￣) /            Подмигивание:    (^ _~) (ﾟｏ⌒) (^ _ - ) == ☆(^ ω~)        (> ω^) (~人^) (^ _ - ) (-_・)(^ _ < )〜☆(^ 人 < )〜☆ ☆⌒(≧▽°) ☆⌒(ゝ。∂)(^ _ < ) (^ _−)☆(･ω < )☆        Извинение :    m(_ _)m(シ_ _)シ m(. .)m <(_ _)>人(_ _*) (*_ _)人 m(_ _; m) (m; _ _)m(シ. .)シ        Письмо :    __φ(．．) (￣ー￣)φ__ __φ(。。) __φ(．．;)        ヾ(`ー´)シφ__ __〆(￣ー￣) …φ(・∀・*) ___〆(・∀・)(^ ▽^)ψ__ …φ(︶▽︶)φ…(. .)φ__ __φ(◎◎ヘ)        Кошка :        人____人≧(◕ ‿‿ ◕)≦(= ^ ･ω･ ^= ) (= ^ ･ｪ･ ^= ) (= ①ω① = ) (= ω = ).nyaa(= ；ｪ； = ) (= ｀ω´ = ) (= ^ ‥ ^= ) (= ノωヽ = )(= ⌒‿‿⌒ = ) (= ^ ◡ ^= ) (= ^ -ω - ^= ) ヾ(= ｀ω´ = )ノ\"(＾• ω •＾) (/ =ω=)/        Музыка :        ヾ(´〇｀)ﾉ♪♪♪ ヘ(￣ω￣ヘ) (〜￣△￣)〜 〜(￣▽￣〜)ヽ(o´∀`)ﾉ♪♬(ﾉ≧∀≦)ﾉ ♪ヽ(^ ^ヽ)♪ ♪(/ _ _) / ♪♪♬((d⌒ω⌒b))♬♪ └(￣ - ￣└)) ((┘￣ω￣)┘ √(￣‥￣√)└(＾＾)┐ ┌(＾＾)┘ ＼(￣▽￣)＼ ／(￣▽￣)／(￣▽￣) / ♫• * ¨ * •.¸¸♪(^ _ ^ ♪)            Оружие:    (・∀・)・・・--------☆(/ -_・) / D・・・・・------→(^ ω^)ノﾞ(((((((((●～ * (-ω - )／占~~~~~(/ ・・)ノ　　((く((へ ―⊂ |= 0ヘ(^^)○∞∞∞∞ヽ(^ ー^) (; ・_・)――――C(・_・)ノ　ζ|||ζ(*＾＾) / ~~~~~~~~~~◎ ￢o(￣ - ￣ﾒ) ―(T_T)→(((￣□)_／(ﾒ｀ﾛ´)︻デ═一(´ - ω･)︻┻┳══━一(ﾒ￣▽￣)︻┳═一 Q(｀⌒´Q)        Другие:    ヾ(・ω・)メ(・ω・)ノ ヽ(∀゜)人(゜∀)ノ ヽ(⌒o⌒)人(⌒ - ⌒)ﾉ(*^ω^)八(⌒▽⌒)八(-‿‿ - )ヽ ＼(＾∀＾)メ(＾∀＾)ノ ヾ(￣ー￣(≧ω≦*)ゝヽ(⌒ω⌒)人(= ^ ‥ ^= )ﾉ ヽ(≧◡≦)八(o ^ ^o)ノ(*・∀・)爻(・∀・*)｡ * :☆(・ω・人・ω・)｡ : ゜☆｡ o(^ ^o)(o ^ ^o)(o ^ ^o)(o^^)o(((￣(￣(￣▽￣)￣)￣)))(ﾟ(ﾟω(ﾟωﾟ(☆ω☆)ﾟωﾟ)ωﾟ)ﾟ) ヾ(・ω・｀)ノヾ(´・ω・)ノ゛ Ψ(｀∀)(∀´)Ψ(っ˘▽˘)(˘▽˘)˘▽˘ς) (((*°▽°*)八(*°▽°*))) ☆ヾ(*´・∀・)ﾉヾ(・∀・`*)ﾉ☆ヽ(･∀･)ﾉ_θ彡☆Σ(ノ `Д´)ノ(*´∇｀)┌θ☆(ﾉ > _ < )ﾉ(￣ω￣)ノﾞ⌒☆ﾐ(o _ _)o(*｀0´)θ☆(メ゜皿゜)ﾉ(o¬‿¬o)…☆ﾐ(*x_x) (╬￣皿￣) = ○＃(￣#)３￣)(; — _ - )――――――C < ―_ - ) ＜(￣︿￣)︵θ︵θ︵☆(＞口＜－) (￣ε(#￣)☆╰╮o(￣▽￣///)ヽ(>_<ヽ) ―⊂|=0ヘ(^‿^) ヘ(>_<ヘ) ￢o (￣‿￣ﾒ) ,(((￣□)_／ ＼_(○￣))),(҂｀ﾛ´)︻デ═一 ＼(º □ º l|l)/ (╯°Д°)╯︵ /(.□. ＼) (¬_¬'')ԅ(￣ε￣ԅ)/(.□.)＼ ︵╰(°益°)╯︵ /(.□. /) (ﾉ-.-)ﾉ…((((((((((((●~* (>_<) !!(ﾒ￣ ￣)_θ☆ﾟ0ﾟ)/(｀⌒*)O-(｀⌒´Q)    (*´ー´)旦 旦(￣ω￣*) (*´з｀)口ﾟ｡ﾟ口(・∀・) (o ^ ^o)且 且(´ω｀*)(￣▽￣)[][](≧▽≦) (*^^)o∀ * ∀o(^^*) (^^)_旦~~~~U_(^^)(*￣▽￣)旦 且(´∀｀*)        ================================        ٩(ˊ〇ˋ*)و просыпается        (￣ ^ ￣)ゞ отдаёт честь        (－‸ლ) фейспалм(facepalm)        (╯°益°)╯彡┻━┻ в гневе бросает стол        (╮° - °)╮┳━━┳(╯°□°)╯ ┻━━┻ взял стол и устроил дебош        ┬─┬ノ(º _ ºノ) поставил стол на место        (oT - T)尸 сдаётся        (͡° ͜ʖ ͡°) мем / лицо Ленни        (ಠ_ಠ) мем / взгляд неодобрения        ◯０o。(ー。ー)y~~курит        (￣﹃￣) голодный        (˘▽˘)っ♨ ест        (っ˘ڡ˘ς) вкусно поел        (x(x_(x_x(O_o)x_x)_x)x) живой среди зомби        (；･ω･)ア указывает        (￣.)o - 【　TV　】 смотрит телевизор        ｀、ヽ｀ヽ｀、ヽ(ノ＞＜)ノ ｀、ヽ｀☂ヽ｀、ヽ ловит зонтик под дождём        (*￣ii￣) кровь из носа        (•)(•)ԅ(‾⌣‾ԅ)        ================================        TM © ® ¢ ? ¥ £        Погода : ☀ ☁ ☂ ☃ ☼ ☽ ☾ ❄ ☄ ★ ☆ ☾ ℃ ℉ ﻩﻩﻩ * ﻩ * ﻩ * ﻩﻩﻩ — ‘๑’ - ϟ ︸        Звезды : ✩ ✪ ✫ ✬ ✭ ✮ ✯ ✰ ҈ ҉ ⁂        Планеты : ♂ ♁ ♀ ☿ ♃ ♄ ♅ ♆ ♇        Символика : ☢ ☣ ☭ ☯ ☮ ☣ ☤ ☬ ☫ ☪ ☨ ☦ ✡ 〄 ♨ ☸ ✙ ✞ 卐 ⌘        Узоры : √ιק √Ìþ moe.ιllιlι.ιl.ҳ̸Ҳ̸ҳ ๑۩۩๑        Смайлы : ソ ッ ヅ ツ ゾ シ ジ ټ ت ン㋛ ☺ ☹ ☻        Цветочки : ✽ ✾ ✿ ❀ ❁ ❂ ❃ ❄ ❅ ❆ ❇ ❈ ❉ ❊ ❋ ٭ ✱ ✲ ✳ ✴ ✵ ✶ ✷ ✸ ✹ ✺ ✻ ✼        Шахматы : ♔ ♕ ♖ ♗ ♘ ♙ ♚ ♛ ♜ ♝ ♞ ♟        Иероглифы : 牡 マ キ グ ナ ル フ ァ 系 路 克 瑞 大 阪 市 立 学 鎰 命 科 ャ マ 能 力 ϒ 人 は 妻 ス テ ィ 要 望 通 り 玉 宏 ¥ サ 丹 谷 Ѫ 灯 影 伝 鶐        Знаки зодиака : ♈ ♉ ♊ ♋ ♌ ♍ ♎ ♏ ♐ ♑ ♒ ♓        ================================        Ѽ — яблоко)        ☢ — ангел что ли…        ◄ — в лево        ► — в право        ▲ — в верх        ▼ — вниз        ↔ — влево вправо        ↨ — вниз вверх        ✖ - крестик        † — крест        √ - галочка        ק — знак числа пи        Ա — омега        ● — большая черная тачика        █ — черный прямоугольник        ▒ — точки с прочерками        ♥ — сердечко        ﭢ — улыбка        ټ — язык        ¶ — пи + точка слева        ┿ — большой плюс        ▄ — нижний квадрат        ▀ — верхний квадрат        Ø — не принадлежит        ۞ — всеми любимая звездочка        ϖ — эммммм        ★ — закрашенная звездочка        ☆ — не закрашенная звездочка        ☻ — смаил        ☺ - белый смаил        ♀♂ — мужское и женское начало        ♠ ♣ ♥ ♦ — черви, крести        ☼ — солнце        ■□■□■ — мини квадратики        ◙ — квадрат с точкой        ▬ — прочерк(можно соединять)        TM — ТМ команда        ♫ ♪ ♫ ♪ — ноты        ۝ — во точняк гамбургир из лимона        ╬═ ═╬ — крестики        ͡๏̯͡๏ — грустный смаилик        ╔╗╚╝ — четыре угла        ◊ — ромб        © ® — copyright и trademark        l ﻉ√٥ — Love(сложный снтаксис)        (-(-_(-_ - )_ - ) - ) — иные миры        ٩(̾●̮̮̃̾•̃̾)۶ — весело(не для Explorer - а)        ٩(●̮̮̃●̃)۶ — смотрелка        ٩(-̮̮̃ - ̃)۶ — забавно        ٩(͡๏̯͡๏)۶ — удивлен        ٩(-̮̮̃•̃)۶ — подмигивание        ٩(x̯x)۶ — бееее        இ — инопланетяшка        ½ — одна вторая        ⅓ — одна третья        ⅔ — две третих        ⅛ — одна восьмая        ⅜ — три восьмых        ⅝ — пять восьмых        ⅞ — семь восьмых        ⓪ ① ② ③ ④ ⑤ ⑥ ⑦ ⑧ ⑨ ⑩ ⑪ ⑫ ⑬ ⑭ ⑮ ⑯ ⑰ ⑱ ⑲ ⑳        ➊➋➌➍➎➏➐➑➒➓        ➀➁➂➃➄➅➆➇➈➉        ⓿ ❶ ❷ ❸ ❹ ❺ ❻ ❼ ❽ ❾ ❿ ⓫ ⓬ ⓭ ⓮ ⓯ ⓰ ⓱ ⓲ ⓳ ⓴                ==================================        Цветы и снежинки :    ✽ ✾ ✿ ✥ ❀ ❁ ❃ ❄ ❅ ❆ ❇ ❈ ❉ ❊ ✢ ✣ ✤ ❋ ٭ ✱ ✲ ✳ ✴ ✶ ✷ ✸ ✹ ✺ ✻ ✼ ⁂        Шахматные фигуры :   ♔♕♖♗♘♙♚♛♜♝♞♟        ==================================        | (•)(•) | Губка Боб        / (•)(•) \ Патрик        ((•)(•)) Скидвард        | (•) | Планктон        | •| |• | Мистер Крабс.        Но, давай честно, ты увидел только сиськи.        ==================================        Когда включили любимый трэк и ты такой :    (͡° ͜ʖ ͡°)        (͡⊙ ͜ʖ ͡⊙)        ＜￣｀ヽ、　　　　　　　／ ￣ ＞        ゝ、　　＼　／⌒ヽ, ノ / ´        ゝ、 （(͡◉ ͜ > ͡◉) ／    > , ノ        ∠_, , , / ´";   
    ifstream fin;
        //fin.open("Histogram.cpp");
        //bracketTest(")()(){}()()()()()(()))){{{{//]]]]]\n}}}}{{{{{{:{[");
        //testTransfer();
        /*fin.open("Test.txt");
        bracketTest(fin);
        cout << endl;
        fin.close();*/
        fin.open("Test.txt");
        Old::bracketTest(fin);
        //Old::easyBracketTest(fin);

}
//, ..., , , <<<  }} > }}}}}}}})0990909)9000> < ))]] }}}}]]]}]