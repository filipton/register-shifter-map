<script lang="ts">
    import D8Segment from "$lib/D8Segment.svelte";
    import Highlight from "svelte-highlight";
    import c from "svelte-highlight/languages/c";
    import styles from "svelte-highlight/styles/base16-ir-black";
    import step1 from "$lib/snippets/step1.c?raw";
    import step2 from "$lib/snippets/step2.c?raw";

    let outputPre: string = "";
    let segments = [0, 0, 0, 0, 0, 0, 0, 0];
    let showDot: boolean = true;
    let segmentsOrder: number[] = [];

    function changeSegment(i: number) {
        segments[i] = 1;
        segments = segments;
        segmentsOrder.push(i);

        if (segmentsOrder.length == 8 - Number(!showDot)) {
            generateDigitMap();
        }
    }

    const digitTemplate = [
        [0, 1, 2, 4, 5, 6], // 0
        [2, 5], //1
        [0, 2, 3, 4, 6], //2
        [0, 2, 3, 5, 6], //3
        [1, 3, 2, 5], //4
        [0, 1, 3, 5, 6], //5
        [0, 1, 3, 4, 5, 6], //6
        [0, 2, 5], //7
        [0, 1, 2, 3, 4, 5, 6], //8
        [0, 1, 2, 3, 5, 6], //9
    ];

    function generateDigitMap() {
        let output = [];
        for (let digit of digitTemplate) {
            output.push(generateDigit(digit));
        }

        let text = `int decDigits[10] = {${output.join(",")}};\n`;
        if (showDot) {
            let dotMod = 1 << segmentsOrder.findIndex((x) => x == 7);
            text += `int dotMod = ${dotMod};\n`;
        }

        console.log(text);
        outputPre = text;
    }

    function generateDigit(template: number[]): number {
        let sum = 0;
        for (let el of template) {
            let idx = segmentsOrder.findIndex((x) => x == el);
            sum += 1 << idx;
        }

        return sum;
    }

    function switchShowDot() {
        showDot = !showDot;
        segments = segments.map((_) => 0);
        segmentsOrder = [];
    }
</script>

<svelte:head>
    {@html styles}
</svelte:head>

<label>
    With dot (8th segment):
    <input type="checkbox" checked={showDot} on:change={switchShowDot} />
</label>

<D8Segment {showDot} {segments} onChangeSegment={(e) => changeSegment(e)} />

<h1>Step 1</h1>
<h2>
    Upload the test code and click on the 8-segment display in order:

    <Highlight language={c} code={step1} />
</h2>

<h1>Output:</h1>
<h2>
    <Highlight language={c} code={outputPre == "" ? "// GENERATED OUTPUT WILL BE HERE!" : outputPre} />
</h2>

<h1>Step 2</h1>
<h2>
    After getting the decDigits array and dotMod int you can use your display. <br />
    dotMod is only visible when the 8th digit is selected. <br /> <br />

    It can be used like this:
    <Highlight language={c} code={step2} />
</h2>
