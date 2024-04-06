<script lang="ts">
    let segments = [0, 0, 0, 0, 0, 0, 0, 0];
    let segmentsOrder: number[] = [];

    function changeSegment(i: number) {
        segments[i] = 1;
        segments = segments;

        segmentsOrder.push(i);

        if (segmentsOrder.length == 8) {
            generateDigitMap();
        }
    }

    const digitTemplate = [
        [0, 1, 2, 3, 4, 5, 6], // 0
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
        for (let digit of digitTemplate) {
            let sum = 0;
            for (let el of digit) {
                let idx = segmentsOrder.findIndex((x) => x == el);
                sum += 1 << idx;
            }

            console.log("Sum: ", sum);
        }
    }
</script>

<table>
    <tr>
        <td></td>
        <td style="width: 150px">
            <button
                class={segments[0] == 0 ? "" : "clicked"}
                on:click={() => changeSegment(0)}
            >
                0
            </button>
        </td>
        <td></td>
    </tr>

    <tr>
        <td style="height: 150px">
            <button
                class={segments[1] == 0 ? "" : "clicked"}
                on:click={() => changeSegment(1)}
            >
                1
            </button>
        </td>
        <td></td>
        <td style="height: 150px">
            <button
                class={segments[2] == 0 ? "" : "clicked"}
                on:click={() => changeSegment(2)}
            >
                2
            </button>
        </td>
    </tr>

    <tr>
        <td></td>
        <td style="width: 150px">
            <button
                class={segments[3] == 0 ? "" : "clicked"}
                on:click={() => changeSegment(3)}
            >
                3
            </button>
        </td>
        <td></td>
    </tr>

    <tr>
        <td style="height: 150px">
            <button
                class={segments[4] == 0 ? "" : "clicked"}
                on:click={() => changeSegment(4)}
            >
                4
            </button>
        </td>
        <td></td>
        <td style="height: 150px">
            <button
                class={segments[5] == 0 ? "" : "clicked"}
                on:click={() => changeSegment(5)}
            >
                5
            </button>
        </td>
    </tr>

    <tr>
        <td></td>
        <td style="width: 150px">
            <button
                class={segments[6] == 0 ? "" : "clicked"}
                on:click={() => changeSegment(6)}
            >
                6
            </button>
        </td>
        <td></td>
    </tr>
</table>

<div
    style="width: 50px; height: 50px; border-radius: 50%; border: 1px solid black; margin-top: 10px; overflow: hidden;"
>
    <button
        class={segments[7] == 0 ? "" : "clicked"}
        on:click={() => changeSegment(7)}
    >
        7
    </button>
</div>

<h1>
    First test with this: <br />
    <pre>int decDigits[10] = &#123;1, 2, 4, 8, 16, 32, 64, 128&#125;;</pre>
</h1>

<style>
    button {
        width: 100%;
        height: 100%;
        border: none;
        cursor: pointer;
    }

    .clicked {
        background-color: red;
    }

    table,
    tr,
    td {
        border-collapse: collapse;
        border: 1px solid black;
    }

    td {
        width: 50px;
        height: 50px;
    }
</style>
